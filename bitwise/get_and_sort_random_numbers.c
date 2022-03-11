/*
 * If you get 10 million random numbers, how do take and sort it(without
 * repeating numbers)?
 *
 * Make sure to use as much less memory as possible.
 *
 * Take the elements only till you get first 0.
 *
 * The basic idea behind this problem is that, you dont need to store the
 * elements in an array or link list. You can use a small array and use each bit
 * of it, to find whether that value was given or not.
 *
 * So, here, the max number of elements can be 500, so we need only below number
 * of integer vars.
 *
 *      = 500/4 = 125
 */
#include <stdio.h>

#define MAX 500
#define NO_OF_INT_ELEMENTS MAX/(sizeof(int))

int global_arr[NO_OF_INT_ELEMENTS];

void print_32bit_int_bitwise(int val, int index)
{
    int bit;
    for (int i=0; i<32; i++) {
        bit = 32-i;
        if (val & (1 << (bit-1))) {
            printf("%d ", ((index * 32) + i + 1));
        }
    } 
    return;
}

void print(void)
{
    int i = 0;
    for (unsigned int i=0; i<NO_OF_INT_ELEMENTS; i++) {
        print_32bit_int_bitwise(global_arr[i], i);
    }
    return;
}

void sort_random_numbers(int arr[], int n)
{
    int bit;
    int update_address;
    int temp;
    for (unsigned int i=0; i<n; i++) {
        temp = arr[i];
        if (temp != 0) {
            update_address = temp/32;
            bit = temp - (update_address * 32);
            bit = 32 - bit;
            *((int *)global_arr + update_address) = *((int *)global_arr + update_address) | (1 << bit);
        } else {
            break;
        }
    }
}

int main() {
    int arr[500] = {4, 1, 100, 5, 1, 44, 67, 76, 1, 5, 0}; 
    sort_random_numbers(arr, 500);
    print();
    printf("\n");

    return 0;
}
