/*
 * Rotate Array
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 * Example 2:
 *
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *
 * Constraints:
 *
 * 1 <= nums.length <= 105
 * -231 <= nums[i] <= 231 - 1
 * 0 <= k <= 105
 *
 *
 * Follow up:
 *
 * Try to come up with as many solutions as you can. There are at least
 * three different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 *
 * 
 *
 * Solution : Solution is tricky to think but easy to solve.
 *
 * 1. Divide in 2 sub-array
 * 2. rotate both sepratly.
 * 3. rotate the complete array.
 *
 * For example,
 *
 * suppose we have this array [1,2,3,4,5,6,7]
 * and we want to rotate it by 3 elements
 *
 * Now, our two arrays are      [1, 2, 3, 4,            5, 6, 7]
 * reverse both separatly as    [4, 3, 2, 1,            7, 6, 5]
 * now reverse the compplete as [5,6,7,1,2,3,4]
 */

#include <stdio.h>

void reverse_array(int* nums, int numsSize)
{
    for (int i = 0, j = numsSize-1; i < j; i++, j--) {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
    }
}

void rotate(int* nums, int numsSize, int k)
{
    /*
     * if k is more than numsize, we just want to rotate only the k%numsSize
     * times.
     * For example, if you have numsSize as 2, and k is 3, then first 2
     * rotations will make the exact same array, only the last 1 rotation
     * will make it differnet. So, the actual number of required rotation is
     * "k%numsize"
     */
    k = k%numsSize;
    if (k && (numsSize > 1)) {
        reverse_array (nums, numsSize-k);
        reverse_array (nums+numsSize-k, k);
        reverse_array (nums, numsSize);
    }
    return;
}

int main(int argc, char **argv)
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    rotate(arr, 7, 3);
    for (int i=0; i<7; i++)
        printf("%d ",arr[i]);

    printf("\n");
    return 0;
}
