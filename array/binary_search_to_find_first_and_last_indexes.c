/*
 * A simple binary search program to find first and last indexes of an element
 * from a sorted array.
 * Best case : When there are only few occurances of the elements being
 * searched O(log n).
 *
 * worst case : When all elements are same as the searched one. Then this will
 * work as a linear algorithm O(n).
 */

#include <stdio.h>
#define SIZE 7

struct output {
    int first;
    int last;
};

void search_first_and_last_occrance(int arr[], int left, int right, int element,
                                    struct output *output)
{
    int first_found = 0;
    for (int i=left; i<=right; i++) {
        if (arr[i] == element) {
            if(!first_found) {
                output->first = i;
                output->last = i;
                first_found = 1;
            } else {
                output->last = i;
            }
        }
    }
    return;
}

int binary_search(int arr[], int left, int right, int element,
                  struct output *output)
{
    int mid;
    int result = -1;

    if (left <= right) {
        mid = (left + right)/2;
        if (arr[mid] == element) {
            search_first_and_last_occrance(arr, left, right, element, output);
        } else if (element < arr[mid]) {
            result = binary_search(arr, left, mid-1, element, output);
        } else {
            result = binary_search(arr, mid+1, right, element, output);
        }
    }

    return result;
}

int main(void)
{
    //int arr[SIZE] = {5, 7, 7, 8, 8, 10, 15};
    int arr[SIZE] = {5, 7, 7, 8, 8, 10, 15};
    struct output output = {-1, -1};
    binary_search(arr, 0, SIZE-1, 8, &output);
    printf("Result : %d %d\n", output.first, output.last);
    return 0;
}
