/*
 * https://www.geeksforgeeks.org/must-do-coding-questions-for-product-based-companies/
 *
 * Delete without head pointer
 *
 * You are given a pointer/ reference to the node which is to be deleted from
 * the linked list of N nodes. The task is to delete the node.
 * Pointer/ reference to head node is not given.
 * Note: No head reference is given to you.
 * It is guaranteed that the node to be deleted is not a tail node in the
 * linked list.
 *
 * Example 1:
 *
 * Input:
 * N = 2
 * value[] = {1,2}
 * node = 1
 * Output: 2
 * Explanation: After deleting 1 from the
 * linked list, we have remaining nodes
 * as 2.
 *
 * Example 2:
 *
 * Input:
 * N = 4
 * value[] = {10,20,4,30}
 * node = 20
 * Output: 10 4 30
 * Explanation: After deleting 20 from
 * the linked list, we have remaining
 * nodes as 10, 4 and 30.
 * 
 * Your Task:
 * You only need to complete the function deleteNode that takes reference to the
 * node that needs to be deleted.
 * The printing is done automatically by the driver code.
 *
 * Expected Time Complexity : O(1)
 * Expected Auxilliary Space : O(1)
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

/*
 * This function can delete any list node without knowing who is pointing to
 * this node. It works on the concept of copying the next node data to this node
 * and deleting the next node and not that node itself.
 */
void delete_node(list *p)
{
    list * temp;
    if (p) {
        /*
         * From the question, "It is guaranteed that the node to be deleted is
         * not a tail node in the linked list. so, no need to worry about 
         * 'next->next' pointers"
         */
        p->data = p->next->data;
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    return;
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

    printf("Print list before node deletion : \n");
    print(first);
    /*
     * Lets delete the first node itself.
     */
    delete_node(first);
    printf("Print list after node deletion : \n");
    print(first);
    return 0;
}
