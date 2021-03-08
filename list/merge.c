/*
 * Given two linked lists, insert nodes of second list into first list at
 * alternate positions of first list.
 * For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6,
 * the first list should become 5->12->7->10->17->2->13->4->11->6 and second
 * list should become empty. The nodes of second list should only be inserted
 * when there are positions available. For example, if the first list is
 * 1->2->3 and second list is 4->5->6->7->8, then first list should
 * become 1->4->2->5->3->6 and second list to 7->8.
 *
 * Use of extra space is not allowed (Not allowed to create additional nodes),
 * i.e., insertion must be done in-place. Expected time complexity is O(n)
 * where n is number of nodes in first list.
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

void merge(list **first, list **second)
{
    list *p = *first;
    list *q = *second;
    list *temp;
    int flag = 1;

    while (p) {
        if (flag == 1) {
            if (!q) {
                break;
            }
            temp = q;
            q = q->next;
            temp->next = p->next;
            p->next = temp;
            flag = 0;
        } else {
            flag = 1;
        }
        p = p->next;
    }
    *second = q;
    return;
}


int main(void)
{
    list *first = NULL;
    list *second = NULL;

    first = add_node(first, 5);
    first = add_node(first, 7);
    first = add_node(first, 17);
    first = add_node(first, 13);
    first = add_node(first, 11);

    second = add_node(second, 12);
    second = add_node(second, 10);
    second = add_node(second, 2);
    second = add_node(second, 4);
    second = add_node(second, 6);
    second = add_node(second, 7);
    second = add_node(second, 8);

    printf("First list(before merge): \n");
    print(first);
    printf("Second list(before merge): \n");
    print(second);
    merge(&first, &second);
    printf("First list(after merge): \n");
    print(first);
    printf("Second list(after merge): \n");
    print(second);
    return 0;
}
