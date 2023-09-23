/*
 * The idea of level order traversal for a tree is that, we traverse each level
 * (left to right) of a tree starting from root node of the tree to the very
 * top (last level) of the tree.
 *
 * For example,
 *
 *                          40      <--------------- Level 0
 *                         /  \
 *                        35  45    <--------------- Level 1
 *                       /      \
 *                      20      90  <--------------- Level 2
 *
 *  The level order traversal (from left to right) for this tree would be,
 *  40, 35, 45, 20, 90
 *
 *  Solution : Maintain a queue from starting(root node) of the tree and keep
 *  pushing the left and right nodes in the queue after printing the node data.
 *  Below, I am pushing only the nodes which has data in it so that we don't
 *  need to do NULL check after getting it from the front of the queue.
 */
#include <iostream>
#include <queue>

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
    queue <tree *> q;
    if (!p) {
        return;
    }
    q.push(p);
    while (!q.empty()) {
        temp = q.front();

        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }

        q.pop();
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
