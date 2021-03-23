/* 
 * https://leetcode.com/problems/house-robber-iii/
 *
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called root.
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that all houses in this place
 * form a binary tree. It will automatically contact the police if
 * two directly-linked houses were broken into on the same night.
 * Given the root of the binary tree, return the maximum amount of money the
 * thief can rob without alerting the police.
 *
 * Input: root = [3,2,3,null,3,null,1]
 *           3
 *          / \
 *         2   3
 *        / \  /\
 *       N   3 N 1
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Input: root = [3,4,5,1,3,null,1]
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9. 
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
 }tree;

unsigned int find_max(tree* p, int break_this_lock)
{
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;

    if (!p)
        return 0;

    if (break_this_lock) {
        /*
        If It is allowed to break this lock, theif can either break
        it or leave it, depending on how he gets max from the below nodes.
        */
        sum1 = find_max(p->left, 0) + find_max(p->right, 0) + p->data;
        sum2 = find_max(p->left, 1) + find_max(p->right, 1);
        return (sum1>sum2) ? sum1 : sum2;
    }
    /* if it is not allowed to break this loack, its strictly not allowed, as the
    parent node has got robbed. so it is strictly not allowed to rob this house.
    so, we dont have much choice here like above condition.
    */
    return find_max(p->left, 1) + find_max(p->right, 1);
}

unsigned int rob(tree* root){
    return find_max(root, 1);
}

tree * add_node(tree *p, int d)
{
    if (!p) {
        p = (tree *) malloc (sizeof(tree));
        p->data = d;
        p->left = NULL;
        p->right = NULL;
    } else if (d <= p->data) {
        p->left = add_node(p->left, d);
    } else {
        p->right = add_node(p->right, d);
    }
    return p;
}

int main(void)
{
    tree *p = NULL;
    p = add_node(p, 50);
    p = add_node(p, 25);
    p = add_node(p, 70);
    p = add_node(p, 30);
    p = add_node(p, 60);
    p = add_node(p, 55);
    p = add_node(p, 65);

    printf("result : %d\n",rob(p));
    return 0;
}
