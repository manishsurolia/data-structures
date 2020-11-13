#include "common.h"
#include "queue.h"

typedef struct tree
{
    struct tree * left;
    struct tree * right;
    int data;
} tree;

static queue q;

/*
 * add_node : add a new node in tree by comparing data. Lesser value data goes
 * in left, and bigger value data goes to right of the tree.
 *
 * Input : tree root node, integer data to be added in the tree
 * Intout : root node
 */
tree *
add_node(tree *p, int data)
{
    if(p == NULL) {
        p = (tree *) malloc (sizeof(tree));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    } else if(data < p->data) {
        p->left = add_node(p->left, data);
    } else {
        p->right = add_node(p->right, data);
    }
    return p;
}

/*
 * print_level_by_level : It prints data of a tree level by level(from left to
 * right). It uses queue data structure, which has been implemented in other
 * file queue.c.
 *
 * All queue declarations are present in queue.h and definitions are present in
 * queue.c file
 *
 * Input : tree root node.
 * Output : TRUE/FALSE
 */

boolean
print_level_by_level(tree *p)
{
    boolean ret = TRUE;

    /*
     * Verify the arguments.
     */
    if (!p) {
        printf("Error: Passed queue is NULL");
        ret = FALSE;
    }

    /*
     * Initialize the queue.
     */
    if (ret && !init_queue(&q)) {
        printf("Error: queue init failed");
        ret = FALSE;
    }

    while (ret) {

        /*
         * print the data in node.
         */
        printf("%d ",p->data);

        /*
         * Enqueue the left node, if not NULL.
         */
        if (p->left) {
            if (!enqueue(&q, p->left)) {
                printf("\nenqueue failed");
                ret = FALSE;
                break;
            }
        }

        /*
         * Enqueue the right node, if not NULL.
         */
        if (ret && p->right) {
            if (!enqueue(&q, p->right)) {
                printf("\nenqueue failed");
                ret = FALSE;
                break;
            }
        }

        /*
         * Get the already enqueued node from queue to print.
         */
        if (ret && !dequeue(&q, (void **)&p)) {
            p = NULL;
            ret = FALSE;
            break;
        }
    }
    printf("\n");
    return ret;
}

int main()
{
    tree * first = NULL;
    first = add_node(first, 40);
    first = add_node(first, 45);
    first = add_node(first, 35);
    first = add_node(first, 20);
    first = add_node(first, 90);
    first = add_node(first, 10);
    first = add_node(first, 95);
    first = add_node(first, 5);
    first = add_node(first, 7);
    first = add_node(first, 88);

    print_level_by_level(first);

    return 0;
}
