/*
 * https://medium.com/techie-delight/binary-tree-interview-questions-and-practice-problems-439df7e5ea1f
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
}tree;

void postorder_print(tree *p)
{
    if (p) {
        postorder_print(p->right);
        printf("%d ",p->data);    
        postorder_print(p->left);
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

    postorder_print(p);
    printf("\n");
    return 0;
}

