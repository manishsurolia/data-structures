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

unsigned long get_num_from_list(struct ListNode* l)
{
    if (!l)
        return 0;

    return (get_num_from_list(l->next) * 10) + l->val;
}

struct ListNode* create_list_from_num(unsigned long num)
{
    if (!num)
        return NULL;

    struct ListNode* tmp = (struct ListNode *)malloc (sizeof(struct ListNode));
    tmp->val = num % 10;
    tmp->next = create_list_from_num(num/10);
    return tmp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    unsigned  long addition = get_num_from_list(l1) + get_num_from_list(l2);
    if (!addition) {
        struct ListNode* tmp =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = 0;
        tmp->next = NULL;
        return tmp;
    } else {
        return create_list_from_num (addition);
    }
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
