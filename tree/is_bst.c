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

    printf("\nis_bst : %d\n", is_bst(p));
    return 0;
}

