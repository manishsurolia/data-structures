/*
 * Search in Rotated Sorted Array
 *
 * There is an integer array nums sorted in ascending order
 * (with distinct values).
 *
 * Prior to being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and
 * become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the rotation and an integer target, return the
 * index of target if it is in nums, or -1 if it is not in nums.
 *
 *
 * Example 1:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * Example 2:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 * Example 3:
 *
 * Input: nums = [1], target = 0
 * Output: -1
 *
 * Constraints:
 *
 * 1 <= nums.length <= 5000
 * -104 <= nums[i] <= 104
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -104 <= target <= 104
 *
 *
 * Follow up: Can you achieve this in O(log n) time complexity?
 */

#include <stdio.h>
int search(int* nums, int numsSize, int target)
{
    int max = -10001;
    int smallest, largest;
    int flag = 1;

    for (int i=0; i<numsSize; i++) {

        if (nums[i] == target) { /* element may be equal, just return the index */
            return i;
        }

        if (flag) {
            if (nums[i] > max) { /* element may be greater */
                max = nums[i];
            } else { /* element may be lesser */
                largest = max;
                smallest = nums[i];

                if ((target > largest) || (target < smallest))
                    return -1;
                else {
                    flag = 0;
                }
            }
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    printf("res = %d\n",search(nums, 7, 0));
    printf("res = %d\n",search(nums, 7, 15));
    return 0;
}
