#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct tree 
{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * add_node (struct tree *p, int data)
{
    if(p == NULL) {
        p = (struct tree *) malloc (sizeof(struct tree));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    } else if(data < p->data) {
        p->left = add_node(p->left, data);
    } else {
        p->right = add_node (p->right, data);
    }
    return p;
}

void print_spiral(struct tree *p)
{
    struct stack *left_to_right = create_stack();
    struct stack *right_to_left = create_stack();

    push(left_to_right, p);

    while(!is_stack_empty(left_to_right) || !is_stack_empty(right_to_left)) {
        while(!is_stack_empty(left_to_right)) {
            p = pop(left_to_right);
            if(p) {
                printf("%d ",p->data);
                push(right_to_left, p->left);
                push(right_to_left, p->right);
            }
        }

        while(!is_stack_empty(right_to_left)) {
            p = pop(right_to_left);
            if(p) {
                printf("%d ",p->data);
                push(left_to_right, p->right);
                push(left_to_right, p->left);
            }
        }
    }
    printf("\n");
    return;
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

    print_spiral(first);

    return 0;
}
