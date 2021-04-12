/*
 * Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a
 * linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 * Constraints:
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
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

struct ListNode* addTwoNumbersInternal(struct ListNode* l1, struct ListNode* l2, int carry)
{
    int element1 = 0;
    int element2 = 0;
    int addition;
    struct ListNode* node;

    if (!l1 && !l2) {
        if (!carry) {
            return NULL;
        } else {
            node = (struct ListNode *) malloc (sizeof(struct ListNode));
            node->val = carry;
            node->next = NULL;
            return node;
        }
    }

    if (l1)
        element1 = l1->val;

    if (l2)
        element2 = l2->val;

    addition = element1 + element2 + carry;
    node = (struct ListNode *) malloc (sizeof(struct ListNode));
    node->val = addition%10;

    if (!l1 || !l2) {
        if (!l1)
            node->next = addTwoNumbersInternal(l1, l2->next, (addition/10));
        else
            node->next = addTwoNumbersInternal(l1->next, l2, (addition/10));
    } else {
        node->next = addTwoNumbersInternal(l1->next, l2->next, (addition/10));
    }

    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    return addTwoNumbersInternal(l1, l2, 0);
}

int main(int argc, char **argv)
{
    struct ListNode * list1 = NULL;
    struct ListNode * list2 = NULL;
    list1 = add_node(list1, 1);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);
    list1 = add_node(list1, 9);

    list2 = add_node(list2, 9);

    print(addTwoNumbers(list1, list2));
    printf("\n");
    return 0;
}
