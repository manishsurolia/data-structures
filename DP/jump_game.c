/*
 * https://leetcode.com/problems/jump-game/
 *
 * 55. Jump Game
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 3 * 104
 * 0 <= nums[i] <= 105
 *
 * Solution : Good example of recursion and dynamic programming(memoiazation).
 */

#include <stdio.h>
#include <stdlib.h>

int jump(int *nums, int numSize, int cur_position, int *memo)
{
    int res = 0;

    if (cur_position == (numSize-1))
        return 1;

    if (cur_position > (numSize-1))
        return 0;

    if (memo[cur_position] != -1)
        return memo[cur_position];
    else {
        for (int i=1; i<=nums[cur_position]; i++)
            res |= jump(nums, numSize, cur_position+i, memo);
        memo[cur_position] = res;
    }

    return res;
}

int canJump(int* nums, int numsSize)
{
    int * memo = (int *) malloc (sizeof(int) * numsSize);

    for (int i=0; i<numsSize; i++)
        memo[i] = -1;

    return jump(nums, numsSize, 0, memo);
}

int main(int argc, char **argv)
{
    int arr1[5] = {2, 3, 1, 1, 4};
    int arr2[5] = {3, 2, 1, 0, 4};
    printf("res = %d\n",canJump(arr1, 5));
    printf("res = %d\n",canJump(arr2, 5));
}
