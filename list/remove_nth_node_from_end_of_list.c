/*
 * Remove Nth Node From End of List
 *
 * Given the head of a linked list, remove the nth node from the end of the
 * list and return its head.
 *
 * Follow up: Could you do this in one pass?
 *
 * Example 1:
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 *
 * Input: head = [1], n = 1
 * Output: []
 * Example 3:
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print(struct ListNode *l)
{
    if (!l)
        return;

    printf("%d ",l->val);
    print(l->next);
}

struct ListNode * add_node(struct ListNode *p, int val)
{
    if (!p) {
        p = (struct ListNode *) malloc (sizeof(struct ListNode));
        p->val = val;
        p->next = NULL;
    } else {
        p->next = add_node (p->next, val);
    }

    return p;
}

struct ListNode* removeNthFromEndInternal(struct ListNode* head, int *n)
{
    struct ListNode* temp;
    if (!head) {
        *n = *n -1;
        return head;
    }

    head->next = removeNthFromEndInternal(head->next, n);

    if (!(*n)) {
        temp = head->next;
        free(head);
        *n = -1;
        return temp;
    }

    *n = *n -1;
    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    return removeNthFromEndInternal(head, &n);
}

int main(int argc, char **argv)
{
    struct ListNode * list = NULL;
    list = add_node(list, 1);
    list = add_node(list, 2);
    list = add_node(list, 3);
    list = add_node(list, 4);
    list = add_node(list, 5);

    print(removeNthFromEnd(list, 2));
    printf("\n");
    return 0;
}
