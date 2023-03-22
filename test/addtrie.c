#include <assert.h>
#include <stdlib.h>
#include <trie.h>

struct word_node *make_trie()
{
    struct word_node *trie = mktrie();

    return trie;
}

void add_first_word(struct word_node *n)
{
    assert((add(n, "hello") == 1));
}

void add_the_same_word(struct word_node *n)
{
    assert((add(n, "hello") == 0));
}

void add_multiple_words(struct word_node *trie)
{
    assert((add(trie, "the") == 1));
    assert((add(trie, "they") == 1));
    assert((add(trie, "there") == 1));
    assert((add(trie, "their") == 1));
    assert((add(trie, "there") == 0));
    assert((add(trie, "hello") == 0));
}

void add_uppercase_word(struct word_node *n)
{
    assert((add(n, "Their") == -1));
    assert((add(n, "Heir") == -1));
    assert((add(n, "hellO") == -1));
    assert((add(n, "helL") == -1));
    assert((add(n, "hElL") == -1));
}

void add_number_words(struct word_node *n)
{
    assert((add(n, "their0") == -1));
    assert((add(n, "the1ir") == -1));
    assert((add(n, "hell0") == -1));
    assert((add(n, "hel1") == -1));
    assert((add(n, "h30") == -1));
    assert((add(n, "3h30") == -1));
}

void add_special_words(struct word_node *n)
{
    assert((add(n, "their()") == -1));
    assert((add(n, "their_") == -1));
    assert((add(n, "_hello") == -1));
    assert((add(n, "hel@") == -1));
    assert((add(n, "hello#") == -1));
    assert((add(n, "!") == -1));
    assert((add(n, "the[]") == -1));
    assert((add(n, "{they}") == -1));
}

int main(void)
{
    struct word_node *trie = NULL;
    assert((trie == NULL));

    trie = make_trie();
    assert((trie != NULL));

    add_first_word(trie);
    add_the_same_word(trie);
    add_multiple_words(trie);
    add_number_words(trie);
    add_special_words(trie);

    free(trie);
    return 0;
}
