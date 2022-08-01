#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    struct tree *left;
    struct tree *right;
    int data;
} tree;

struct tree *add_node (struct tree *p, int data)
{
    if (!p) {
        p = (struct tree *) malloc (sizeof(tree));
        p->left = NULL;
        p->right = NULL;
        p->data = data;
    } else if (data <= p->data) {
        p->left = add_node(p->left, data);
    } else {
        p->right = add_node(p->right, data);
    }

    return p;
}

int find_height(tree *p)
{
    int right_subtree_height;
    int left_subtree_height;
    int height = 0;

    if (p) {
        right_subtree_height = find_height(p->right);
        left_subtree_height = find_height(p->left);
        if (right_subtree_height > left_subtree_height) {
            height = right_subtree_height + 1;
        } else if (left_subtree_height >= right_subtree_height) {
            height = left_subtree_height + 1;
        }
    }
    return height;
}

// print LNR.
void print(tree *p)
{
    if (p) {
        print (p->left);
        printf("%d ", p->data);
        print (p->right);
    }
}

int main(void)
{
   tree *first  = NULL;
   first = add_node(first, 5);
   first = add_node(first, 3);
   first = add_node(first, 7);
   first = add_node(first, 2);
   first = add_node(first, 4);
   first = add_node(first, 6);
   first = add_node(first, 8);
   first = add_node(first, 16);
   first = add_node(first, 32);
   first = add_node(first, 64);

   print(first);
   printf("\n");
   printf("Height : %d\n", find_height(first));
   return 0;
}
