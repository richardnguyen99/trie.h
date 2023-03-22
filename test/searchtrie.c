#include <assert.h>
#include <stdlib.h>
#include <trie.h>

struct word_node *make_trie()
{
    struct word_node *trie = mktrie();

    return trie;
}

void initialize_trie(struct word_node *trie)
{
    assert((add(trie, "hello") == 1));
    assert((add(trie, "the") == 1));
    assert((add(trie, "they") == 1));
    assert((add(trie, "there") == 1));
    assert((add(trie, "their") == 1));
}

void search_existing_words(struct word_node *trie)
{
    assert((search(trie, "hello") == 1));
    assert((search(trie, "the") == 1));
    assert((search(trie, "they") == 1));
    assert((search(trie, "there") == 1));
    assert((search(trie, "their") == 1));
}

void search_nonexisting_words(struct word_node *trie)
{
    assert((search(trie, "hell") == 0));
    assert((search(trie, "thee") == 0));
    assert((search(trie, "thei") == 0));
    assert((search(trie, "thy") == 0));
    assert((search(trie, "theirs") == 0));
}

void search_empty_trie()
{
    struct word_node *trie = NULL;

    assert((search(trie, "they") == -1));
    assert((search(trie, "there") == -1));
    assert((search(trie, "their") == -1));
}

void search_empty_word(struct word_node *trie)
{
    assert((search(trie, "hello") == 1));
    assert((search(trie, "") == -1));
    assert((search(trie, "they") == 1));
    assert((search(trie, "") == -1));
}

void search_invalid_words(struct word_node *n)
{
    assert((search(n, "Their") == -1));
    assert((search(n, "Heir") == -1));
    assert((search(n, "hellO") == -1));
    assert((search(n, "helL") == -1));
    assert((search(n, "hElL") == -1));

    assert((search(n, "their0") == -1));
    assert((search(n, "the1ir") == -1));
    assert((search(n, "hell0") == -1));
    assert((search(n, "hel1") == -1));
    assert((search(n, "h30") == -1));
    assert((search(n, "3h30") == -1));

    assert((search(n, "their()") == -1));
    assert((search(n, "their_") == -1));
    assert((search(n, "_hello") == -1));
    assert((search(n, "hel@") == -1));
    assert((search(n, "hello#") == -1));
    assert((search(n, "!") == -1));
    assert((search(n, "the[]") == -1));
    assert((search(n, "{they}") == -1));
}

int main(void)
{
    struct word_node *trie = NULL;
    assert((trie == NULL));

    trie = make_trie();
    assert((trie != NULL));

    initialize_trie(trie);

    search_existing_words(trie);
    search_nonexisting_words(trie);
    search_empty_trie();
    search_empty_word(trie);
    search_invalid_words(trie);

    free(trie);
    return 0;
}
