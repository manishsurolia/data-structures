#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree * left;
    struct tree * right;
    int data;
};

struct tree * add_node(struct tree *p, int data)
{
    if(!p) {
        p = (struct tree *) malloc (sizeof(struct tree));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    } else if(data < p->data) {
        p->left = add_node(p->left, data);
    } else {
        p->right = add_node(p->right, data);
    }
    return p;
}

struct tree * LCA(struct tree *p, int data1, int data2)
{
    struct tree *left;
    struct tree *right;
    struct tree *ret;

    if(!p)
        return p;

    if((p->data == data1) || (p->data == data2))
        return p;

    left = LCA(p->left, data1, data2);
    right = LCA(p->right, data1, data2);

    if(!left && !right)
        ret = NULL;
    else if(left && right)
        ret = p;
    else
        ret = left ? left : right;

    return ret;
}

int main()
{
    struct tree * first = NULL;
    struct tree * searched_node = NULL;
    first = add_node(first, 40);
    first = add_node(first, 45);
    first = add_node(first, 35);
    first = add_node(first, 20);
    first = add_node(first, 90);
    first = add_node(first, 10);
    first = add_node(first, 95);
    first = add_node(first, 5);
    first = add_node(first, 7);
    first = add_node(first, 88);

    searched_node = LCA(first, 7, 95);

    if(searched_node) {
        printf("lca is : %d\n",searched_node->data);
    } else {
        printf("found lca is NULL\n");
    }

    return 0;
}
