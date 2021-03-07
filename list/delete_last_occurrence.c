/*
 * Loop through the whole list and use a double pointer to keep track of the
 * node containing the address of last occurrence node.
 *
 * Created Linked list: 1 --> 2 --> 3 --> 4 --> 5 --> 4 --> 4 --> NULL
 * List after deletion of 4: 1 --> 2 --> 3 --> 4 --> 5 --> 4 --> NULL
 *
 * Given a liked list and a key to be deleted. Delete last occurrence of key
 * from linked. The list may have duplicates.
 *
 * Examples:
 *
 * Input:   1->2->3->5->2->10, key = 2
 * Output:  1->2->3->5->10
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

list * delete_last_occurrence(list *p, int data)
{
    list *start = p;
    list *first = NULL;
    list *second = NULL;
    list *temp;
    int flag = 0;

    if (!p) {
        return NULL;
    }

    /*
     * If, there is only one node in the list and
     * 1. That node has the data to be deleted, delete it and return NULL.
     * 2. That node does not have the data to be deleted, just return the list.
     */
    if ((!p->next)) {
        if (p->data == data) {
            free(p);
            return NULL;
        } else {
            return p;
        }
    }

    /*
     * Special case, where the first node itself matches the data.
     */
    if (p->data == data) {
        first = second;
        second = p;
        flag = 1;
    }

    while (p->next) {
        if (p->next->data == data) {
            first = second;
            second = p;
        }
        p = p->next;
    }

    /*
     * First condition is Special case, where the very fisrt node matched the
     * data and then no other matches.
     */
    if ((second == start) && flag) {
        temp = start;
        start = start->next;
        free(temp);
    } else {
        temp = second->next;
        second->next = second->next->next;
        free(temp);
    }
    return start;
}


int main(void)
{
    list *first = NULL;

    first = add_node(first, 1);
    first = add_node(first, 2);
    first = add_node(first, 3);
    first = add_node(first, 2);
    first = add_node(first, 5);

    printf("Print list before delete : \n");
    print(first);
    first = delete_last_occurrence(first, 2);
    printf("Print list after delete : \n");
    print(first);
    return 0;
}
