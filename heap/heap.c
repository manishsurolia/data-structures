/*
 * This is exact implementation of heap how it is described in the README.
 */
#include <stdio.h>

void swap (int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void adjust(int index, int *arr, int len)
{
    int left = (index*2)+1;
    int right = (index*2)+2;

    if (left > len-1)
        return; /* If left is not there in array, surely right wont be there */

    if (right <= (len-1)) { /* Both children are present */
        if (arr[left] >= arr[right]) {
            if (arr[left] > arr[index]) {
               swap (&arr[index], &arr[left]);
            }
        } else {
            if (arr[right] > arr[index]) {
                swap (&arr[index], &arr[right]);
            }
        }
    } else { /* Only left child is present */
        if (arr[left] > arr[index]) {
            swap (&arr[index], &arr[left]);
        }
    }

    adjust (left, arr, len);
    adjust (right, arr, len);

    return;
}


void heapify(int *arr, int len)
{
    for (int i=len-1; i >= 0; i--)
        adjust(i, arr, len);
}

int delete(int *arr, int len)
{
    int res = arr[0];
    arr[0] = arr[len-1];   /* Keep the last heap index value at 0 index */
    adjust(0, arr, len-1); /* Maintain heap properties */
    return res;
}

void heap_sort(int *arr, int len)
{
    /*
     * 1. heapify the array.
     * 2. Delete elements from top and store them at the end of the heap.
     */
    heapify(arr, len);
    for (int i=(len-1); i>=0; i--) {
        arr[i] = delete(arr, i+1);
    }
    return;
}

int main(int argc, char **argv)
{
   int arr[11] = {5, 7, 3, 1, 4, 6, 2, 10, 15, 12, 11};
   int error = 0;
   heap_sort(arr, 11);
   for (int i=0; i <11; i++) {
       printf("%d ",arr[i]);
   }
   printf("\n");
}
