#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list *next;
    int data;
}list;


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

unsigned char find_loop(list *p)
{
    list *fast, *slow;

    if(!p || !p->next) {
        return 0;
    } else {
        slow = p;
        fast = p->next;
    }

    while(1) {
        if (!fast) {
            return 0;
        } else if (slow == fast) {
            return 1;
        } else {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            } else {
                /*
                 * fast has reached at the end of list(NULL).
                 * Hence, no loop.
                 */
                return 0;
            }
        }
    }
    return 0;
}

int main(void)
{
    list *first = NULL;
    list *p = NULL;

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

   /*
    * Create loop here. Just making first node of list as the next of last node.
    * You can change below code to change the loop.
    */

    if (first) {
        p = first;
        while (p->next) {
            p = p->next;
        }
        p->next = first;
    }

    printf("Loop present = %d\n",find_loop(first));
    return 0;
}
