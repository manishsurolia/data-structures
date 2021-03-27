#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 26
#define TRUE 1
#define FALSE 0

typedef struct trie {
    unsigned char is_leaf;
    struct trie * children[CHAR_SIZE];
} trie;

trie * create_node(void)
{
    trie * node = (trie *) malloc (sizeof(trie));

    for (int i=0; i<CHAR_SIZE; i++)
        node->children[i] = NULL;

    node->is_leaf = 0;
    return node;
}

unsigned char is_leaf(trie *p)
{
    if (p->is_leaf)
        return TRUE;

    return FALSE;
}

void add_string(trie *p, char *str)
{
    int i;
    int len = strlen(str);
    int index;

    for (int i=0; i<len; i++) {
        index = str[i] - 'a';
        if (p->children[index] == NULL)
            p->children[index] = create_node();

        p = p->children[index];
    }
    p->is_leaf = 1;
    return;
}

void print(trie *p, char str[], int level)
{
    if (is_leaf(p)) {
        str[level] = '\0';
        printf("%s\n",str);
    }

    for (int i=0; i<CHAR_SIZE; i++) {
        if (p->children[i]) {
            str[level] = i + 'a';
            print(p->children[i], str, level+1);
        }
    }
}

int main()
{
    trie * root = create_node();
    add_string(root, "manprakash");
    add_string(root, "savita");
    add_string(root, "a");
    add_string(root, "apple");
    add_string(root, "an");
    add_string(root, "and");
    add_string(root, "manisha");
    add_string(root, "manish");
    add_string(root, "meenakshi");
    add_string(root, "pratiksha");
    add_string(root, "arjun");

    char str[20];
    print(root, str, 0);
    return 0;
}
