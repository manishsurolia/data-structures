/*
 * Conver string to digit.
 *
 * "1234" ==> 1234 (number).
 * "+1234" ==> 1234 (number).
 * "-1234" ==> -1234 (number).
 * "123w4" ==> wrong
 */
#include <stdio.h>
#include <string.h>

int convert(char *str, int len, int *res)
{
    int sign = 1;
    int start = '0';
    int digit;
    int result = 0;
    int i = 0;

    if(str[0] == '-') {
        sign = -1;
        i++;
    }

    if(str[0] == '+') {
        sign = +1;
        i++;
    }

    while (i<len) {
        if (str[i] < '0' || str[i] > '9')
            return 1; /* Error code */
        digit = str[i] - start;
        result = digit + (result * 10);
        i++;
    }
    *res = result * sign;
    return 0;
}

int main(int argc, char **argv)
{
    int res;
    if (!convert("1234", strlen("1234"), &res)) {
        printf("result : %d\n",res);
    } else {
        printf("Error\n");
    }

    if (!convert("-1234", strlen("-1234"), &res)) {
        printf("result : %d\n",res);
    } else {
        printf("Error\n");
    }

    if (!convert("+1234", strlen("+1234"), &res)) {
        printf("result : %d\n",res);
    } else {
        printf("Error\n");
    }

    if (!convert("1w234", strlen("1w234"), &res)) {
        printf("result : %d\n",res);
    } else {
        printf("Error\n");
    }

    return 0;
}
