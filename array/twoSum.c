/*
 * Given an array of integers numbers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 *
 * Return the indices of the two numbers (1-indexed) as an integer array answer
 * of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 *
 * Example 1:
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 *
 * Example 2:
 *
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 *
 * Example 3:
 *
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 *
 * Constraints:
 *
 * 2 <= numbers.length <= 3 * 104
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in increasing order.
 * -1000 <= target <= 1000
 * Only one valid answer exists.
 *
 *
 * Solution: We take the benefit of the fact the array is sorted.
 *
 * One way is to solve this with brute force method, in which we one element
 * with every other element present in the array. But its a brute force method
 * and the complexity is of squre(n). so its not a good method.
 *
 * second way is to take benefit of the fact that the array is sorted.
 *
 * Initially, we keep 2 pointers (at first index and at the last index) and then
 * keep comparing them(incrementing and decrementing) accordingly.
 *
 * For example, for target = 18, find the indexes in below array.
 *
 *  1  3  7  9  11  13  16
 *  
 *  lets first set two pointers at first and last index as below:
 *
 *  1  3  7  9  11  13  16
 *  ^                    ^
 *
 *  1+16=17, this is lesser than 18, hence, increase the left counter as below:
 *
 *  1  3  7  9  11  13  16
 *     ^                ^
 *
 *  3+16 = 19, this is greater than 18, hence, decrease the right counter as
 *  below: 
 *
 *  1  3  7  9  11  13  16
 *     ^            ^
 *
 *  3+13 = 16, is again lesser than 18, so,
 *
 *  1  3  7  9  11  13  16
 *        ^         ^ 
 *
 *  7+13 = 20 is greateer, so
 *
 *  1  3  7  9  11  13  16
 *        ^     ^
 *
 *  7+11 = 18.. got the answer, break the loop and return.        
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int ptr1, ptr2;
    ptr1 = 0;
    ptr2 = numbersSize-1;
    int *output = malloc(sizeof(int) * 2);
    *returnSize = 2;

    while (ptr1 < ptr2) {
        if ((numbers[ptr1] + numbers[ptr2]) < target)
            ptr1++;
        else if((numbers[ptr1] + numbers[ptr2]) > target)
            ptr2--;
        else {
            output[0] = ptr1+1;
            output[1] = ptr2+1;
            break;
        }
    }
    return output;
}

int main(int argc, char **argv)
{
    int arr[7] = {1, 3, 7, 9, 11, 13, 16};
    int *result;
    int result_size;

    result = twoSum(arr, 7, 18, &result_size);
    printf("Result is :\n");
    for (int i=0; i<result_size; i++) {
        printf("%d ",result[i]);
    }
    free(result);
    printf("\n");
    return 0;
}
