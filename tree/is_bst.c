/*
 * https://www.geeksforgeeks.org/must-do-coding-questions-for-product-based-companies/
 * https://practice.geeksforgeeks.org/problems/check-for-bst/1
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
}tree;

void print(tree *p)
{
    if (p) {
        print(p->left);
        printf("%d ",p->data);    
        print(p->right);
    }
    return;
}

void free_tree(tree *p)
{
    if (!p)
        return;

    free_tree(p->left);
    free_tree(p->right);
    free(p);
    return;
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
/*
 * Good solution.
 * The problem with below bad solution is that, it just checks whether
 * the left child and right child is following the properties of BST or not.
 * Hence, it is localized BST check, which cause problem is such below
 * scenario:
 *
 *              5
 *             /\
 *            4  8
 *               /\
 *              3  9
 *
 * The bad solution below with say that its a BST, because at each node level,
 * left and right, follows the property of BST, but actually its not BST,
 * because 3 is lesser than the top most node 5, which is not possible in a
 * BST.
 */
int is_valid_bst(tree* root, tree* smaller, tree* bigger)
{
    if (!root)
        return 1;

    if ((smaller && (root->data <= smaller->data)) ||
        (bigger && (root->data >= bigger->data)))
        return 0;

    return is_valid_bst(root->left, smaller, root) &&
           is_valid_bst(root->right, root, bigger);
}

int is_bst(tree* root)
{
    return is_valid_bst(root, NULL, NULL);
}

/*
 * Bad Solution. Never use this to check for BST
 */
/*
int is_bst(tree *p)
{
    int res1 = 1;
    int res2 = 1;
    if (!p) {
        return 1;
    } else {
        if (p->left) {
            if ((p->left->data <= p->data)) {
                res1 = is_bst(p->left);
            } else {
                res1 = 0;
            }
        }

        if (res1 && p->right) {
            if ((p->right->data >= p->data)) {
                res2 = is_bst(p->right);
            } else {
                res2 = 0;
            }
        }
        
        return (res1 && res2) ? 1 : 0;    
    }
}
*/

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
    printf("is_bst : %d\n", is_bst(p));
    free_tree(p);


    p = NULL;
    p = add_node(p, 5);
    p = add_node(p, 4);
    p = add_node(p, 8);
    p = add_node(p, 7);
    p = add_node(p, 9);

    /* make it non-bst */
    printf("is_bst : %d\n", is_bst(p));
    p->right->left->data = 3;
    printf("is_bst : %d\n", is_bst(p));
    free_tree(p);

    return 0;
}

