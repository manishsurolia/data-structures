#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * add_node(struct tree *p, int data)
{
    if(p == NULL) {
        p = (struct tree *) malloc (sizeof(struct tree));
        p->left = NULL;
        p->right = NULL;
        p->data = data;
    } else if (data < p->data) {
        p->left = add_node(p->left, data);
    } else {
        p->right = add_node(p->right, data);
    }
    return p;
}

int sum_of_all_nodes(struct tree *p)
{
    int sum = 0;
    if(p) {
        sum = p->data;
        sum = sum + sum_of_all_nodes(p->left);
        sum = sum + sum_of_all_nodes(p->right);
    }
    return sum;
}

int main()
{
    struct tree * first = NULL;
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

    printf("sum of all nodes = %d\n", sum_of_all_nodes(first));

    return 0;
}


