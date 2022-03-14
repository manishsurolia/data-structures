/*
 * find a sub-tree inside another tree.
 *
 * Tree:
 *
 *                 100
 *              /       \
 *           50          150
 *        /     \       /     \
 *     25         75   125     175
 *
 * Sub-tree:
 *
 *              150
 *            /     \
 *          125      175
 *
 * Return 1 when sub-tree is present in a tree, Otherwise return 0.
 *
 * Solution : Just get all the tree nodes values inside an array for both the
 * trees, and just compare one array inside another.
 *
 * This approach will save lots of multiple comparisons when comparison is done
 * with the tree search itself.
 */
#include <stdio.h>
#include <stdlib.h>

int is_sub_array_present(int array[], int arr_size, int sub_arrary[], int subarr_size)
{
    int j = 0;

    for (int i=0; i<arr_size; i++) {
        if (array[i] == sub_arrary[j]) {
            j++;
            if (j == subarr_size) {
                return 1; // sub-array found
            }
        } else {
            j = 0;
        }
    }
    return 0; // sub-array not found.
}

struct tree {
    struct tree *left;
    struct tree *right;
    int data;
};

struct tree *add_node(struct tree *p, int data)
{
    if (!p) {
        p = (struct tree *) malloc (sizeof(struct tree));
        p->left = NULL;
        p->right = NULL;
        p->data = data;
    } else {
        if (data <= p->data) {
            p->left = add_node(p->left, data);
        } else {
            p->right = add_node(p->right, data);
        }
    }
    return p;
}

void print_NLR_to_array(struct tree *p, int arr[], int i)
{
    if (p) {
        arr[i++] = p->data;
        print_NLR_to_array(p->left, arr, i);
        print_NLR_to_array(p->right, arr, i);
    }
    return;
}

void main(void)
{
    struct tree *root = NULL;
    struct tree *sub_tree = NULL;

    int root_array[7];
    int sub_tree_array[3];

    root = add_node(root, 100);
    root = add_node(root, 50);
    root = add_node(root, 150);
    root = add_node(root, 25);
    root = add_node(root, 75);
    root = add_node(root, 125);
    root = add_node(root, 175);

    sub_tree = add_node(sub_tree, 150);
    sub_tree = add_node(sub_tree, 125);
    sub_tree = add_node(sub_tree, 175);

    print_NLR_to_array(root, root_array, 0);
    print_NLR_to_array(sub_tree, sub_tree_array, 0);

    printf("present : %d\n", is_sub_array_present(root_array, 7, sub_tree_array, 3));

    return;
}
