/*
 * Given a linked list consisting of L nodes and given a number N.
 * The task is to find the Nth node from the end of the linked list.
 *
 * Example 1:
 *
 * Input:
 * N = 2
 * LinkedList: 1->2->3->4->5->6->7->8->9
 * Output: 8
 * Explanation: In the first example, there
 * are 9 nodes in linked list and we need
 * to find 2nd node from end. 2nd node
 * from end os 8.
 *
 * Example 2:
 *
 * Input:
 * N = 5
 * LinkedList: 10->5->100->5
 * Output: -1
 * Explanation: In the second example, there
 * are 4 nodes in the linked list and we
 * need to find 5th from the end. Since 'n'
 * is more than the number of nodes in the
 * linked list, the output is -1.

 * Your Task:
 * The task is to complete the function getNthFromLast() which takes two
 * arguments: reference to head and N and you need to return Nth from the end
 * or -1 in case node doesn't exist..
 *
 * Note:
 * Try to solve in single traversal.
 *
 * Expected Time Complexity: O(N).
 * Expected Auxiliary Space: O(1).
 *
 * Constraints:
 * 1 <= L <= 10^3
 * 1 <= N <= 10^3
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

int getNthFromLast(list *p, unsigned int N)
{
    list *first;
    list *second;
    int i, ret=0;

    if (!p || !N) {
        return -1; 
    }

    /*
     * Boundary condition : If there is only one node in the list and the passed
     * value of N is also 1, then just return the value of the node.
     */

    if ((N==1) && (!p->next)) {
        return p->data;
    }
    
    /*
     * Set the first pointer to the start of the list and let it run for the
     * N nodes.
     */
    first = p;
    for (i=0; i<(N-1); i++) {
        if (first->next == NULL) {
            ret = -1;
            break;
        }
        first = first->next;
    }

    /*
     * If ret is -1, then we dont have enough node in the list.
     * Just return -1.
     */
    if (ret == -1) {
        return ret;
    }

    /*
     * Now, set the second pointer to the start of the list and let both
     * pointers run till the end of the list and return the value at the second
     * pointer.
     */

    second = p;
    while(first->next != NULL) {
        first = first->next;
        second = second->next;
    }

    return second->data;
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

    printf("output : %d\n",getNthFromLast(first, 1));

    return 0;
}
