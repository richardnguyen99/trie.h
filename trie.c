#include "trie.h"
#include <string.h>

int ord(char c)
{
    return (int)c - (int)'a';
}

int dummy()
{
    return 0;
}

struct word_node *mktrie()
{
    struct word_node *dict = NULL;

    dict = (struct word_node *)malloc(sizeof(struct word_node));

    if (!dict)
        return dict;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
        dict->node[i] = NULL;

    dict->eow = 0;

    return dict;
}

int add(struct word_node *trie, char *word)
{
    if (!trie)
        return 0;

    size_t n = strlen(word);

    if (n == 0)
        return 0;

    for (size_t i = 0; i < n; ++i)
    {
        int alphabet_order = ord(word[i]);

        if (alphabet_order < 0 || alphabet_order > 25)
            return -1;

        if (trie->node[alphabet_order] == NULL)
            trie->node[alphabet_order] = mktrie();

        // If the trie->node[i] is still NULL, there was an error happening
        // during allocation.
        if (trie->node[alphabet_order] == NULL)
            return -2;

        trie = trie->node[alphabet_order];
    }

    if (trie->eow == 1)
        return 0;

    trie->eow = 1;

    return 1;
}

int search(struct word_node *trie, char *word)
{
    if (!trie)
        return 0;

    return 1;
}

int delete(struct word_node *trie, char *word)
{
    if (!trie)
        return 0;

    return 1;
}

int deltrie(struct word_node *trie)
{
    if (!trie)
        return 0;

    return 1;
}

int copy(struct word_node *src, struct word_node **dest)
{
    if (!src)
        return 0;

    return 1;
}
