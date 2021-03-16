/*
 * Write a function to return an n element in Fibonacci sequence.
 * The Fibonacci numbers are the numbers in the following integer sequence.
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
 *
 * Given a number n, print n-th Fibonacci Number.
 *
 * For example, if I ask to print 0th Fibonacci Number, its 0.
 * 1st Fibonacci Number, its 1.
 * 2nd Fibonacci Number, its 1.
 * 3rd Fibonacci Number, its 2.
 * 4th Fibonacci Number, its 3 and so on.
 *
 * Solution : Any number at any position in the Fibonacci series, is addition
 * of last number and last-to-last number. We can use this concept in
 * recursion.
 *
 * Exception : The first 2 counts are exeption to this.
 * Meaning, 0th position number is just 0.
 * and 1st position number is just 1.
 *
 * We will use the above logic and the exception in the program below;
 */

#include <stdio.h>
int fib(int n)
{
    if (n < 2) {
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main(int argc, char **argv)
{
    int n = 11;
    printf("Result : %d\n",fib(n));
    return 0;
}
