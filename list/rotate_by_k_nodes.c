/*
 * Given a singly linked list, rotate the linked list counter-clockwise by k
 * nodes. Where k is a given positive integer. For example, if the given linked
 * list is 10->20->30->40->50->60 and k is 4, the list should be modified
 * two 50->60->10->20->30->40. Assume that k is smaller than the count of
 * nodes in linked list.
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

list * rotate_by_k_nodes(list *p, int k)
{
    list *r = p;
    list *temp;
    list *q;

    if (!p || (k <= 0)) {
        return p;
    }

    /*
     * Now, Jump by k-1 nodes.
     */
    while (k-1) {
        p = p->next; 
        if (!p) {
            /*
             * Passed k is smaller than the number of nodes in the list.
             * just return the same list.
             */ 
            return r;
        }
        k--;
    }

    /*
     * Put start of q list after k nodes and end the r lis with NULL.
     */
    q=p->next;
    p->next = NULL; 

    /*
     * Now, we have 2 lists.
     * first one is r(for k nodes).
     * second is q(for remaining nodes).
     */

    /*
     * Rotate the list q and a the end of the list r list has to be present.
     */
    while (q) {
        temp = r;
        r = q;
        q = q->next;
        r->next = temp;
    }

    return r;
}


int main(void)
{
    list *first = NULL;

    first = add_node(first, 10);
    first = add_node(first, 20);
    first = add_node(first, 30);
    first = add_node(first, 40);
    first = add_node(first, 50);
    first = add_node(first, 60);

    printf("Print list before reverse : \n");
    print(first);
    first = rotate_by_k_nodes(first, 10);
    printf("Print list after reverse : \n");
    print(first);
    return 0;
}
