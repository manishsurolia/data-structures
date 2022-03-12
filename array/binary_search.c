/*
 * A simple binary search program.
 */

#include <stdio.h>
#define SIZE 7

int binary_search(int arr[], int left, int right, int element)
{
    int mid;
    int result = -1;

    if (left <= right) {
        mid = (left + right)/2;
        if (arr[mid] == element) {
            result = mid;
        } else if (element < arr[mid]) {
            result = binary_search(arr, left, mid-1, element);
        } else {
            result = binary_search(arr, mid+1, right, element);
        }
    }

    return result;
}

int main(void)
{
    int arr[SIZE] = {5, 7, 7, 8, 8, 10, 15};
    printf("Result : %d\n", binary_search(arr, 0, SIZE-1, 10));
    return 0;
}
