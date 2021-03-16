/*
 * The problem with the old recursion method of Fibonacci series is that,
 * it calculates the nth position number multiple times.
 * 
 * We can avoid it by storing the numbers once calculated.
 */

#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    int *arr;
    int res;

    if (n < 2) {
        return n;
    }

    arr = (int *) malloc (sizeof(int) * (n+1));
    arr[0] = 0;
    arr[1] = 1;

    for (int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    res = arr[n];
    free(arr);
    return res;
}

int main(int argc, char **argv)
{
    int n = 9;

    printf("Result : %d\n",fib(n));
    return 0;
}
