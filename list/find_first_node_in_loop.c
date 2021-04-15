/*
 * 142. Linked List Cycle II
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * There is a cycle in a linked list if there is some node in the list that
 * can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's
 * next pointer is connected to. Note that pos is not passed as a parameter.
 *
 * Notice that you should not modify the linked list.
 *
 *
 *
 * Example 1:
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 *
 * Example 2:
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 *
 * Constraints:
 *
 * The number of the nodes in the list is in the range [0, 104].
 * -105 <= Node.val <= 105
 *pos is -1 or a valid index in the linked-list.
 *
 *
 *Follow up: Can you solve it using O(1) (i.e. constant) memory?
 *
 */

#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode * add_node(struct ListNode *p, int val)
{
    if (!p) {
        p = (struct ListNode *) malloc (sizeof(struct ListNode));
        p->val = val;
        p->next = NULL;
    } else {
        p->next = add_node(p->next, val);
    }
    return p;
}
 
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;

    if (!head)  /* If the list is empty, just return NULL */
        return NULL;

    while (1) {
        if (!fast->next || !fast->next->next)
            return NULL;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) /* Got the cycle, break loop */
            break;
    }

    /*
     * Start 2 pointers, first from head and second from the last common point.
     * where they meet, its the start of loop.
     */
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }

    return head;
}

int main(int argc, char **argv)
{
    struct ListNode * first = NULL;
    struct ListNode * res = NULL;

    first = add_node(first, 1);
    first = add_node(first, 2);
    first = add_node(first, 3);
    first = add_node(first, 4);
    first->next->next->next->next = first->next; /* 4th next node is 2 */
    res = detectCycle (first);
    printf("res = %d\n",res->val);
    return 0;
}

