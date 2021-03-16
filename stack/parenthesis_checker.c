/*
 * https://www.geeksforgeeks.org/must-do-coding-questions-for-product-based-companies/
 * https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
 *
 * Parenthesis Checker
 *
 * Given an expression string x. Examine whether the pairs and the orders of
 * “{“,”}”,”(“,”)”,”[“,”]” are correct in exp. For example, the function
 * should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for
 * exp = “[(])”.
 *
 * Example 1:
 *
 * Input:
 * {([])}
 * Output:
 * true
 * Explanation:
 * { ( [ ] ) }. Same colored brackets can form
 * balaced pairs, with 0 number of
 * unbalanced bracket.
 *
 *
 * Example 2:
 *
 * Input:
 * ()
 * Output:
 * true
 * Explanation:
 * (). Same bracket can form balanced pairs,
 * and here only 1 type of bracket is
 * present and in balanced way.
 *
 * Example 3:
 *
 * Input:
 * ([]
 * Output:
 * false
 * Explanation:
 * ([]. Here square bracket is balanced but
 * the small bracket is not balanced and
 * Hence , the output will be unbalanced.
 *
 * Your Task:
 * This is a function problem. You only need to complete the function ispar()
 * that takes a string as a parameter and returns a boolean value true if
 * brackets are balanced else returns false. The printing is done automatically
 * by the driver code.
 *
 * Expected Time Complexity: O(|x|)
 * Expected Auixilliary Space: O(|x|)
 *
 */

/*
 * It takes a string and finds out whether the paranthesis are arranged properly
 * or not.
 */
#include <stdio.h>
unsigned char ispar(char *str)
{
    char arr[100]; /* Taking this as a stack. */
    int i=0;
    while (*str != '\0') {
        if ((*str == '[') ||
                (*str == '(') ||
                (*str == '{')) {
            arr[i] = *str; 
            i++;
        } else if (((*str == ']') && (arr[i-1] == '[')) ||
                ((*str == ')') && (arr[i-1] == '(')) ||
                ((*str == '}') && (arr[i-1] == '{'))) {
            i--;
        } else {
            return 0;
        }
        str++;
    }
    if (i>0) {
        /*
         * still there is something remaining after readig all the data from
         * str.
         */ 
        return 0;
    } else {
        return 1;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
   printf("result : %d\n", ispar("([])")); 
   return 0;
}

