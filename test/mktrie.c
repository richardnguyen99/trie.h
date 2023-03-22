#include <assert.h>
#include <stdlib.h>
#include <trie.h>

struct word_node *make_trie()
{
    struct word_node *trie = mktrie();

    return trie;
}

int main(void)
{
    struct word_node *trie = NULL;
    assert((trie == NULL));

    trie = make_trie();
    assert((trie != NULL));

    struct word_node *tries[100];
    for (int i = 0; i < 100; ++i)
    {
        tries[i] = make_trie();
        assert((tries[i] != NULL));
    }

    free(trie);
    for (int i = 0; i < 100; ++i)
        free(tries[i]);

    return 0;
}
