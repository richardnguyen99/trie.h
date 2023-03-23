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

void delete_existing_words(struct word_node *trie)
{
    assert((delete (trie, "hello") == 1));
    assert((delete (trie, "the") == 1));
}

void add_deleted_words(struct word_node *trie)
{
    assert((add(trie, "hello") == 1));
    assert((add(trie, "the") == 1));
}

void search_origin_words(struct word_node *trie)
{
    assert((search(trie, "hello") == 1));
    assert((search(trie, "the") == 1));
    assert((search(trie, "they") == 1));
    assert((search(trie, "there") == 1));
    assert((search(trie, "their") == 1));
}

void delete_nonexisting_words(struct word_node *trie)
{
    assert((delete (trie, "hell") == 0));
    assert((delete (trie, "thee") == 0));
    assert((delete (trie, "thei") == 0));
    assert((delete (trie, "thy") == 0));
    assert((delete (trie, "theirs") == 0));
}

void delete_invalid_words(struct word_node *n)
{
    assert((delete (NULL, "invalid") == -1));
    assert((delete (n, "") == -1));

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

    delete_existing_words(trie);
    add_deleted_words(trie);
    search_origin_words(trie);

    delete_nonexisting_words(trie);
    delete_invalid_words(trie);
    search_origin_words(trie);

    free(trie);
    return 0;
}
