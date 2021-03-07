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

list * rotate(list *p)
{
    list *r = NULL;
    list *temp;

    while (p) {
        temp = r;
        r = p;
        p = p->next;
        r->next = temp;
    }

    return r;
}


int main(void)
{
    list *first = NULL;

    first = add_node(first, 1);
    first = add_node(first, 2);
    first = add_node(first, 3);
    first = add_node(first, 4);
    first = add_node(first, 5);
    first = add_node(first, 6);
    first = add_node(first, 7);
    first = add_node(first, 8);
    first = add_node(first, 9);
    first = add_node(first, 10);

    printf("Print list before reverse : \n");
    print(first);
    first = rotate(first);
    printf("Print list after reverse : \n");
    print(first);
    return 0;
}
