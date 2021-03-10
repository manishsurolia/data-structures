/*
 * https://medium.com/techie-delight/binary-tree-interview-questions-and-practice-problems-439df7e5ea1f
 *
 * In-place convert a binary tree to its sum tree
 *
 * Given a Binary Tree where each node has positive and negative values.
 * Convert this to a tree where each node contains the sum of the left and
 * right sub trees in the original tree. The values of leaf nodes are
 * changed to 0.
 *
 *
 * For example, the following tree
 *
 *                 10
 *              /      \
 *            -2        6
 *           /   \      /  \
 *          8     -4    7    5
 *
 *          should be changed to
 *
 *
 *          20(4-2+12+6)
 *              /      \
 *        4(8-4)      12(7+5)
 *          /   \      /  \
 *        0      0    0    0
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
}tree;

int create_sum_tree(tree *p)
{
    int temp;
    if (!p) {
        return 0;
    } else if (!p->left && !p->right) {
        temp = p->data; 
        p->data = 0;
        return temp;
    } else {
        temp = p->data;
        p->data = create_sum_tree(p->left);
        p->data = p->data + create_sum_tree(p->right);
        return temp + p->data;
    } 
}

void print(tree *p)
{
    if (p) {
        print(p->left);
        printf("%d ",p->data);
        print(p->right);
    }
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

    printf("Tree(Before making it sum tree) : \n");
    print(p);
    printf("\nTree(After making it sum tree) : . Final sum : %d\n",
            create_sum_tree(p));
    print(p);
    printf("\n");
    return 0;
}

