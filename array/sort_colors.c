/*
 * Given an array nums with n objects colored red, white, or blue,
 * sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue, respectively.
 */
#include <stdio.h>


void sortColors(int* nums, int numsSize)
{
    int count_zeros=0;
    int count_ones=0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 0)
            count_zeros++;
        if (nums[i] == 1)
            count_ones++;
    }
    
    for (int i=0; i<numsSize; i++) {
        if (count_zeros) {
            nums[i] = 0;
            count_zeros--;
        } else if (count_ones) {
            nums[i] = 1;
            count_ones--;
        } else {
            nums[i] = 2;
        }
    }
    return;
}

int main(int argc, char **argv)
{
    int arr[10] = {0,1,2,0,1,0,2,2,2,0};
    sortColors(arr, 10);
    for (int i=0; i<10; i++) {
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}
