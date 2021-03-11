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

int identical(tree *p, tree *q)
{
    if (!p && !q) {
        return 1;
    } else {
        if (!p || !q) {
            return 0;
        } else if (p->data == q->data) {
            return (identical(p->left, q->left) &&
                    identical(p->right, q->right));
        } else {
            return 0;
        }
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
    tree *q = NULL;
    p = add_node(p, 50);
    p = add_node(p, 25);
    p = add_node(p, 70);
    p = add_node(p, 30);
    p = add_node(p, 60);
    p = add_node(p, 55);
    p = add_node(p, 65);

    q = add_node(q, 50);
    q = add_node(q, 25);
    q = add_node(q, 70);
    q = add_node(q, 30);
    q = add_node(q, 60);
    q = add_node(q, 55);
    q = add_node(q, 65);

    printf("identical : %d",identical(p, q));

    printf("\n");
    return 0;
}

