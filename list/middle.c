#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list * next;
    int data;
} list;

list * add_node(list *p, int data)
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


list * find_middle(list *p)
{
    list *slow, *fast;

    if (p) {
        fast = slow = p;
    } else {
        return p;
    }

    /*
     * Assuming that the list does not have any loop.
     */
    while(1) {
        if (fast->next) {
            fast = fast->next->next;
        } else {
            break;
        }
        slow = slow->next;
    }

    return slow;
}


int main(void)
{
    list *first = NULL;
    list *middle = NULL;

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
    first = add_node(first, 11);
    first = add_node(first, 12);
    first = add_node(first, 13);
    first = add_node(first, 14);
    first = add_node(first, 15);
    first = add_node(first, 16);
    first = add_node(first, 17);
    first = add_node(first, 18);
    first = add_node(first, 19);
    first = add_node(first, 20);
    first = add_node(first, 21);
    first = add_node(first, 22);
    first = add_node(first, 23);
    first = add_node(first, 24);
    first = add_node(first, 25);
    first = add_node(first, 26);
    first = add_node(first, 27);
    first = add_node(first, 28);
    first = add_node(first, 29);

    middle = find_middle(first);

    if (middle) {
        printf("\nmiddle->data : %d\n",middle->data);
    }
    return 0;
}
