/*
 * Reverse a list by a count.
 * Example:
 * 1->2->3->4->5->6->7->8->NULL
 *
 * if count is 3, then rotate first 3(3->2->1) and then next 3(6->5->4),..and so
 * on.
 *
 * 3->2->1->6->5->4->8->7->NULL
 */
#include <stdio.h>
#include <stdlib.h>

struct list {
    struct list *next;
    int data;
};

struct list *get_n_reversed_elements(struct list *p, int n, struct list **first, struct list **last)
{
    int count = 0;
    struct list *r = NULL;
    struct list *temp;

    while (p && (count < n)) {
        *first = p;
        if (!count) {
            *last = p;
        }
        count++;

        temp = p;
        p = p->next;
        temp->next = r;
        r = temp;

        if (!p) {
            (*last)->next = NULL;
            return NULL;
        }
    }
    return p;
}

struct list *add_node(struct list *p, int data)
{
    if (!p) {
        p = (struct list *) malloc (sizeof(struct list));
        p->data = data;
        p->next = NULL;
    } else {
        p->next = add_node(p->next, data);
    }
    return p;
}

void print(struct list *p)
{
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    return;
}

int main(void)
{
    struct list *list = NULL;
    struct list *first = NULL;
    struct list *last = NULL;

    int flag = 0;
    struct list *top;
    struct list *last_last = NULL;

    list = add_node(list, 1);
    list = add_node(list, 2);
    list = add_node(list, 3);
    list = add_node(list, 4);
    list = add_node(list, 5);
    list = add_node(list, 6);
    list = add_node(list, 7);
    list = add_node(list, 8);
    list = add_node(list, 9);
    list = add_node(list, 10);
    list = add_node(list, 11);
    list = add_node(list, 12);

    print(list);
    printf("\n");
    while (list) {
        list = get_n_reversed_elements(list, 2, &first, &last);

        if (last_last) {
            last_last->next = first;
        }

        if (!flag) {
            top = first;
            flag = 1;
        }
        last_last = last;
    }
    print(top);
    printf("\n");
    return 0;
}
