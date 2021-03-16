/*
 * AVL Tree : An AVL tree is to overcome issue with a binary search tree, where
 * sometimes the tree height goes un-nessesarily very high, because data is
 * entered in some sorted way.
 *
 * example of a binary tree, when data is entered in sorted fashion:
 *
 * 10
 *   \
 *    20
 *      \
 *       30
 *        \
 *         40
 *
 * The search in this binary tree is worst.
 * so, to improve on it, AVL tree can help which can have at max of 1/-1
 * difference in the height of any 2 leaf nodes.
 *
 * check the add_node of AVL tree below to find the difference between normal
 * add node and this one.
 *
 * There are 4 types of rotations introduced here. LL, LR, RL, RR
 */         

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

/*
 * Height of a node in tree.
 */
int height(node *p)
{
    int lh=0;
    int rh=0;

    if (!p)
        return 0;

    if (p->left)
        lh = p->left->height + 1;

    if (p->right)
        rh = p->right->height + 1;

    if (rh > lh)
        return rh;

    return lh;
}

/*
 * Difference between heights of the left and right sub-tree.
 */
int balance_factor (node *p)
{
    int rh=0;
    int lh=0;

    if (!p)
        return 0;

    if (p->left)
        lh = p->left->height;

    if (p->right)
        rh = p->right->height;

    return (lh - rh);
}

/*
 *  Rotate left will happen in below similar scenario to balance the tree.
 *
 *      10
 *        \
 *        20
 *          \
 *           30
 */
node * rotate_left(node *p)
{
    node * temp;

    temp = p->right;
    p->right = temp->left;
    temp->left = p;

    p->height = height(p);
    temp->height = height(temp);

    return temp;
}

/*
 *  Rotate right will happen in below similar scenario to balance the tree.
 *
 *             30
 *            /
 *           20
 *          /
 *         10
 */
node * rotate_right(node *p)
{
    node * temp;

    temp = p->left;
    p->left = temp->right;
    temp->right = p;

    p->height = height(p);
    temp->height = height(temp);

    return temp;
}

/*
 * This is needed when the new node is added in left to the left of the root.
 */
node * LL (node * p)
{
    return rotate_right(p);
}

/*
 * This is needed when the new node is added in right to the left of the root.
 */
node * RL (node *p)
{
    p->right = rotate_right(p->right);
    return rotate_left(p);
}

/*
 * This is needed when the new node is added in left to the right of the root.
 */
node * LR (node *p)
{
    p->left = rotate_left(p->left);
    return rotate_right(p);
}

/*
 * This is needed when the new node is added in right to the right of the root.
 */
node * RR (node *p)
{
    return rotate_left(p);
}

node * add_node (node *p, int data)
{
    if(!p) {
        p = (node *) malloc (sizeof(node));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        p->height = 0;
    } else if (data <= p->data) {
        p->left = add_node(p->left, data);
        if (balance_factor(p) == 2) {
            if (data < p->left->data) {
                p = LL(p);
            } else {
                p = LR(p);
            }
        }
    } else {
        p->right = add_node (p->right, data);
        if (balance_factor(p) == -2) {
            if (data > p->right->data) {
                p = RR(p);
            } else {
                p = RL(p);
            }
        }
    }
    p->height = height(p);
    return p;
}

void print(node *p)
{
    if (!p)
        return;

    print(p->left);
    printf("data : %d, height : %d, balance factor : %d\n",
            p->data, p->height, balance_factor(p));
    print(p->right);
    return;
}


int main(void)
{
    struct node *first = NULL;
    first = add_node(first, 30);
    first = add_node(first, 20);
    first = add_node(first, 25);
    first = add_node(first, 40);
    first = add_node(first, 45);
    first = add_node(first, 42);
    first = add_node(first, 43);
    print(first);
    return 0;
}



