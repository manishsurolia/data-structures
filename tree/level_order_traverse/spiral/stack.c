#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack * create_stack()
{
    struct stack * p = NULL;
    p = (struct stack *) malloc (sizeof(struct stack));
    if(p == NULL) {
        printf("Error: malloc failed");
        return NULL;
    }
    p->top = -1;
    return p;
}

void push(struct stack *p,void *data)
{
    p->top = p->top + 1;
    p->array[p->top] = data;
}

void * pop(struct stack *p)
{
    void * temp = p->array[p->top];
    p->top = p->top - 1;
    return temp;
}

uchar is_stack_full(struct stack *p)
{
    return (p->top == (STACK_SIZE - 1)) ? TRUE : FALSE;
}

uchar is_stack_empty(struct stack *p)
{
    return (p->top == -1) ? TRUE : FALSE;
} 
