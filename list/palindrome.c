/*
 * Given a singly linked list of characters, write a function that returns
 * true if the given list is a palindrome, else false.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 250

typedef struct list {
    struct list * next;
    char c;
} list;

list * add_node(list * p, char c)
{
    if (!p) {
        p = (list *) malloc (sizeof(list));
        p->c = c;
        p->next = NULL;
    } else {
        p->next = add_node(p->next, c);
    }
    return p;
}

void print(list *p)
{
    while (p) {
        printf("%c ",p->c);
        p = p->next;
    }
    printf("\n");
    return;
}

int is_string_palindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return 0;
        }
    }
    return 1;
}

int is_palindrome(list *p)
{
    char str[MAX_STR_LEN];
    int i = 0;
    while(p) {
        str[i++] = p->c;
        p = p->next;
    }
    str[i] = '\0';
    return is_string_palindrome(str);
}


int main(void)
{
    list *first = NULL;

    first = add_node(first, 'R');
    first = add_node(first, 'A');
    first = add_node(first, 'D');
    first = add_node(first, 'A');
    first = add_node(first, 'R');

    printf("List: \n");
    print(first);
    printf("Is the list palindrom : %d\n",is_palindrome(first));
    return 0;
}
