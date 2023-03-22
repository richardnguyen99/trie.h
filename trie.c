#include "trie.h"

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
