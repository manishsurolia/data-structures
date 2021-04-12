#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s)
{
    int size = strlen(s);
    int **arr;
    int max_row=0, max_col=0;
    char *result;
    int i,j,offset;
    
    if (size == 1)
        return s;

    /* Create double array */
    arr = (int **)malloc(size * sizeof(int *));
    for (i=0; i<size; i++)
         arr[i] = (int *)malloc(size * sizeof(int));

    for (i=0, offset=0; i<=size; i++,offset++) {
        for (j=0; j<(size-offset); j++) {
            if (offset == 0) {
                arr[j][j] = 1;
                max_row = j;
                max_col = j+offset;
            } else if (offset == 1) {
                if (s[j+offset] == s[j]) {
                    arr[j][j+offset] = 1;
                    max_row = j;
                    max_col = j+offset;
                } else {
                    arr[j][j+offset] = 0;
                }
            } else {
                if ((s[j] == s[j+offset]) && arr[j+1][j+offset-1]) {
                        arr[j][j+offset] = 1;
                        max_row = j;
                        max_col = j+offset;
                } else {
                    arr[j][j+offset] = 0;
                }
            }
        }
    }
    
    result = malloc((sizeof(char) * (max_col-max_row)) + 2);
    result[0] = s[max_row];
    result[1] = '\0';
    if (max_col > max_row) {
        for (i=max_row, j=0; i<=max_col; i++,j++) {
            result[j] = s[i];
        }
        result[j] = '\0';
    }
    
    return result;
    
}

int main(int argc, char **argv)
{
    char *str = "aaaabbaa";
    char *result = longestPalindrome(str);

    printf("%s\n",result);
    return 0;
}
