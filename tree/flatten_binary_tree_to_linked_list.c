/*
 * Given the root of a binary tree, flatten the tree into a "linked list":
 *
 * The "linked list" should use the same TreeNode class where the right
 * child pointer points to the next node in the list and the left child
 * pointer is always null.
 * The "linked list" should be in the same order as a pre-order
 * traversal of the binary tree.
 *
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * This should result is tree as below:
 *
 *  1->2->3->4->5->6 
 *
 * This tree has only right child. all left childs are NULL.
 *
 * Example1:
 * Input: root = [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 *
 * Example2:
 * Input: root = []
 * Output: []
 *
 * Example3:
 * Input: root = [0]
 * Output: [0]
 *
 * Can you flatten the tree in-place (with O(1) extra space)?
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root)
{
    struct TreeNode* temp;
    if (!root)
        return;

    // 1. Call for the left node first
    flatten(root->left);

    //2. If p->left is there, add it to the p->right
    if(root->left){
        temp = root->right;
        root->right = root->left;
        root->left = NULL;

        while (root->right)
            root = root->right;

        root->right = temp;
    }

    // 3. Call for the right node.
    flatten(root->right);

    return;
}

struct TreeNode * add_node(struct TreeNode *p, int d)
{
    if (!p) {
        p = (struct TreeNode *) malloc (sizeof(struct TreeNode));
        p->val = d;
        p->left = NULL;
        p->right = NULL;
    } else if (d <= p->val) {
        p->left = add_node(p->left, d);
    } else {
        p->right = add_node(p->right, d);
    }
    return p;
}

void print(struct TreeNode *p)
{
    if (p) {
        print(p->left);
        printf("%d ",p->val);
        print(p->right);
    }
    return;
}

int main(void)
{
    struct TreeNode *p = NULL;
    p = add_node(p, 50);
    p = add_node(p, 25);
    p = add_node(p, 70);
    p = add_node(p, 30);
    p = add_node(p, 60);
    p = add_node(p, 55);
    p = add_node(p, 65);

    printf("list before flatten :\n");
    print(p);
    printf("\n");
    flatten(p);
    printf("list after flatten :\n");
    print(p);
    printf("\n");

    return 0;
}
