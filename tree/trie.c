#include <stdio.h>
#include <stdlib.h>

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

