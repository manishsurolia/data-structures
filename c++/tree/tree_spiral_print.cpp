/*
 * The idea of spiral order traversal for a tree is that, we traverse each level
 * in opposite fashion (for example, level 0 will be traversed from left to
 * right and level 1 will be traversed from right to left.. and so on.
 *
 * For example,
 *
 *                          40      <--------------- Level 0
 *                         /  \
 *                        35  45    <--------------- Level 1
 *                       /      \
 *                      20      90  <--------------- Level 2
 *
 *  The spiral order traversal (from left to right) for this tree would be,
 *  40, 35, 45, 90, 20
 *
 *  Solution : Maintain two stacks 'left_to_right' and 'right_to_left' and push
 *  the top root node to the 'left_to_right' and when you traverse this stack,
 *  keep adding the child nodes in the other 'right_to_left' stack. Once this
 *  stack is empty move to the other stack and start doing the same thing in
 *  vice versa manner. Do it in a loop until both stacks are empty.
 */
#include <iostream>
#include <stack>

using namespace std;

typedef struct tree {
    struct tree *left;
    struct tree *right;
    int data;
} tree;

struct tree * add_node (struct tree *p, int val)
{
    if (!p) {
        p = new tree;
        p->data = val;
        p->left = NULL;
        p->right = NULL;
    } else if (val < p->data) {
        p->left = add_node(p->left, val);
    } else {
        p->right = add_node(p->right, val); 
    }
    return p;
}

void level_order_print (tree *p)
{
    tree *temp;
    stack <tree *> left_to_right;
    stack <tree *> right_to_left;
    if (!p) {
        return;
    }
    left_to_right.push(p);
    while (!left_to_right.empty() || !right_to_left.empty()) {
        while (!left_to_right.empty()) {
            temp = left_to_right.top();
            cout << temp->data << " ";

            if (temp->left) {
                right_to_left.push(temp->left);
            }

            if (temp->right) {
                right_to_left.push(temp->right);
            }

            left_to_right.pop();
        }

        while (!right_to_left.empty()) {
            temp = right_to_left.top();
            cout << temp->data << " ";

            if (temp->right) {
                left_to_right.push(temp->right);
            }

            if (temp->left) {
                left_to_right.push(temp->left);
            }

            right_to_left.pop();
        }
    }
    return;
}

int main(void)
{
    tree *p = NULL;
    p = add_node(p, 40);
    p = add_node(p, 45);
    p = add_node(p, 35);
    p = add_node(p, 20);
    p = add_node(p, 90);
    p = add_node(p, 10);
    p = add_node(p, 95);
    p = add_node(p, 5);
    p = add_node(p, 7);
    p = add_node(p, 88);

    level_order_print(p);
    cout << "\n";
    return 0;
}
