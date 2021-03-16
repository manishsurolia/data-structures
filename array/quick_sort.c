/*
 * Quick Sort : quick sort works on divide and conqure method.
 */
#include <stdio.h>
 void swap(int *p, int *q)
 {
    int temp = *p;
    *p = *q;
    *q = temp;
 }

int partition (int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        i++; /* Mandatory to avoid recursion loop like [5, 5] */
        while (arr[i] <= pivot) {
            i++;
        }

        j--; /* Mandatory to avoid recursion loop like [5, 5] */
        while(arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[low], &arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int pi;
    if (low < high) {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi);
        quick_sort(arr, pi+1, high);
    }
    return;
}

int main(int argc, char **argv)
{
    int i;
    int arr[11] = {9, 4, 7, 2, 8, 5, 9, 5, 1, 3, 1234};
    quick_sort(arr, 0, 10);
    for (i=0; i<11; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
