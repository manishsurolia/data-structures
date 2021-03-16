/*
 * https://www.geeksforgeeks.org/must-do-coding-questions-for-product-based-companies/
 * Count ways to reach the n'th stair
 * 
 * There are N stairs, a person standing at the bottom wants to reach the top.
 * The person can climb either 1 stair or 2 stairs at a time.
 * Count the number of ways, the person can reach the top (order does matter).
 *
 * Example 1:
 * Input:
 * N = 4
 * Output: 5
 * Explanation:
 * You can reach 4th stair in 5 ways.
 * Way 1: Climb 2 stairs at a time.
 * Way 2: Climb 1 stair at a time.
 * Way 3: Climb 2 stairs, then 1 stair and then 1 stair.
 * Way 4: Climb 1 stair, then 2 stairs then 1 stair.
 * Way 5: Climb 1 stair, then 1 stair and then 2 stairs.
 *
 *
 * Example 2:
 * Input:
 * N = 10
 * Output: 89
 * Explanation:
 * There are 89 ways to reach the 10th stair.
 */
#include <stdio.h>

int count(int n)
{
    /*
     * it takes 0 ways to reach 0th stair.
     * and takes 1 way to reach 1st stair from 0th stair. ('1')
     * and takes 2 ways to reach 2nd stair from 0th stair. ('1+1' and '2')
     * Hence, the below if condition.
     */

    if (n<=2) {
        return n;
    } else {
        /*
         * Else, any other stair(nth) can be reached by below ways.
         * ==> ways to reach 'n-1' stairs + ways to reach 'n-2' stairs.
         */ 
        return (count(n-1) + count(n-2));
    }
}

int main(int argc, char **argv)
{
    int n = 10;
    printf("Result : %d\n",count(n));
    return 0;
}
