/*
 * Number is represented in linked list such that each digit corresponds to a
 * node in linked list. Add 1 to it. For example 1999 is represented
 * as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct list * next;
    int data; 
} list;

list * add_node(list * p, int data)
{
    if (!p) {
        p = (list *) malloc (sizeof(list));
        p->data = data;
        p->next = NULL;
    } else {
        p->next = add_node(p->next, data);
    }
    return p;
}

void print(list *p)
{
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int add_one_internal(list *p)
{
    int temp;
    int carry;

    if (!p) {
        return 1;
    } else {
        carry = add_one_internal(p->next);
        temp = p->data + carry;
        if (temp > 9) {
            p->data = temp%10;
            return temp/10;
        } else {
            p->data = temp;
            return 0;
        }
    }   
}

void add_one(list **p)
{
    list *temp = *p;
    list *extra;

    if (add_one_internal(temp)) {
       extra = (list *) malloc (sizeof(list)); 
       extra->data = 1;
       extra->next = *p;
       *p = extra;
    }
}

int main(void)
{
    list *first = NULL;

    first = add_node(first, 9);
    first = add_node(first, 9);
    first = add_node(first, 9);
    first = add_node(first, 9);

    printf("Print list before adding 1: \n");
    print(first);
    add_one(&first);
    printf("Print list after adding 1 : \n");
    print(first);
    return 0;
}
