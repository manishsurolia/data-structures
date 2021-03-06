/*
 * Given a singly linked list consisting of N nodes.
 * The task is to remove duplicates (nodes with duplicate values) from the
 * given list (if exists).
 * Note: Try not to use extra space. Expected time complexity is O(N).
 * The nodes are arranged in a sorted way.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

list * add_node(struct list *p, int data)
{
    if (!p) {
        p = (struct list *) malloc (sizeof(list));
        p->data = data;
        p->next = NULL;
    } else {
        p->next = add_node(p->next, data);
    }
    return p;
}

void remove_duplicates(list *p)
{
    list *temp;
    while (p) {
        if (p->next && (p->next->data == p->data)) {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
    return;
}

void print_list(list *p)
{
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    list *first = NULL;

    first = add_node(first, 1);
    first = add_node(first, 1);
    first = add_node(first, 1);
    first = add_node(first, 1);
    first = add_node(first, 2);
    first = add_node(first, 2);
    first = add_node(first, 2);
    first = add_node(first, 2);
    first = add_node(first, 3);
    first = add_node(first, 3);
    first = add_node(first, 5);
    first = add_node(first, 6);
    first = add_node(first, 7);
    first = add_node(first, 7);
    first = add_node(first, 9);
    first = add_node(first, 10);
    first = add_node(first, 10);
    first = add_node(first, 12);
    first = add_node(first, 12);
    first = add_node(first, 14);
    first = add_node(first, 15);
    first = add_node(first, 16);
    first = add_node(first, 17);
    first = add_node(first, 17);
    first = add_node(first, 19);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 20);
    first = add_node(first, 21);
    first = add_node(first, 22);
    first = add_node(first, 22);
    first = add_node(first, 24);
    first = add_node(first, 25);
    first = add_node(first, 26);
    first = add_node(first, 26);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);
    first = add_node(first, 28);

    printf("List before duplicates removal :\n");
    print_list(first);
    remove_duplicates(first);
    printf("List after duplicates removal :\n");
    print_list(first);
    return 0;

}

