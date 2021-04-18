/*
 * 5735. Maximum Ice Cream Bars
 *
 * It is a sweltering summer day, and a boy wants to buy some ice cream bars.
 *
 * At the store, there are n ice cream bars. You are given an array costs of
 * length n, where costs[i] is the price of the ith ice cream bar in coins.
 * The boy initially has coins coins to spend, and he wants to buy as many
 * ice cream bars as possible.
 *
 * Return the maximum number of ice cream bars the boy can buy with coins coins.
 *
 * Note: The boy can buy the ice cream bars in any order.
 *
 *
 *
 * Example 1:
 *
 * Input: costs = [1,3,2,4,1], coins = 7
 * Output: 4
 * Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
 * Example 2:
 *
 * Input: costs = [10,6,8,7,7,8], coins = 5
 * Output: 0
 * Explanation: The boy cannot afford any of the ice cream bars.
 * Example 3:
 *
 * Input: costs = [1,6,3,1,2,5], coins = 20
 * Output: 6
 * Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 *
 *
 * Constraints:
 *
 * costs.length == n
 * 1 <= n <= 105
 * 1 <= costs[i] <= 105
 * 1 <= coins <= 108
 *
 */

#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int maxIceCream(int* costs, int costsSize, int coins){
    int res = 0;
    int i;

    mergeSort(costs, 0, costsSize-1);

    if (coins < costs[0])
        return 0;

    for (i=0; i<costsSize; i++) {
        if (coins) {
            coins = coins - costs[i];
            if (coins < 0)
                break;
        } else {
            break;
        }
    }

    return i;
}

int main(int argc, char **argv)
{
   int costs1[5] = {1,3,2,4,1};
   int costs2[6] = {10,6,8,7,7,8};
   int costs3[6] = {1,6,3,1,2,5};
   printf("result : %d\n",maxIceCream(costs1, 5, 7));
   printf("result : %d\n",maxIceCream(costs2, 6, 5));
   printf("result : %d\n",maxIceCream(costs3, 6, 20));
   return 0;
}
