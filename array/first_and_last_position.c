/*
 * Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order,
 * find the starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * Follow up: Could you write an algorithm with O(log n) runtime complexity?
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 *
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 *-10^9 <= target <= 10^9
 *
 */
#include <stdio.h>
#include <stdlib.h>

int find_index(int* nums, int low, int high, int target)
{
    int mid;
    if (!nums)
        return -1;
    
    if (low != high)
        mid = (low + high)/2;
    else
        if (nums[low] == target)
            return low;
        else
            return -1;
    
    if (target == nums[mid]) {
        return mid;
    } else if (target < nums[mid]) {
        return find_index(nums, low, mid, target);
    } else {
        return find_index(nums, mid+1, high, target);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int *ret = malloc (sizeof(int) * 2);
    *returnSize = 2;

    if (!numsSize) {
        ret[0] = ret[1] = -1;
        return ret;
    }

    int index = find_index(nums, 0, numsSize-1, target);
    
    if (index == -1) {
        ret[0] = ret[1] = -1;
        return ret;
    }

    for (i=index; i>=0; i--) {
        if (nums[i] != target) {
            break;
        }
    }
    ret[0] = ++i;
        
    for (i=index; i<numsSize; i++) {
        if (nums[i] != target) {
            break;
        }
    }
    ret[1] = --i;
    
    return ret;
}

int main(int argc, char **argv)
{
    int size;
    int *ret;
    int arr[6] = {5, 7, 7, 8, 8, 10};
    ret = searchRange(arr, 6, 8, &size);
    printf("result : %d, %d\n",ret[0], ret[1]);
    return 0;
}
