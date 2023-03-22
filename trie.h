#ifndef __TRIE_H
#define __TRIE_H 1

#include <stddef.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

/**
 * @brief Core data structure containing the information for working with a trie
 */
struct word_node
{
    struct word_node *node[26]; // English alphabet
    short eow;                  // End of word
};

/**
 * @brief Dummy test function for checking compiling and linking in build
 *
 * @return 0
 */
int dummy();

/**
 * @brief Initialize a trie data structure.
 *
 * This function will initialize a trie and return the root which stands for
 * an empty string.
 *
 * @return On success, it returns a trie allocated in the heap. On error, a
 * `NULL` is returned instead.
 */
struct word_node *mktrie();

/**
 * @brief Add a word to a trie.
 *
 * @param trie An existing trie
 * @param word A given word
 * @return On success, it returns 1 meaning the word has been appened to the
 * lists. If the word is already existing, 0 is returned instead. If there is
 * an error happening, -1 is returned instead.
 */
int add(struct word_node *trie, char *word);

/**
 * @brief Check if a given word exists in a given trie.
 *
 * @param trie An existing trie
 * @param word A given word
 * @return On success, it returns 1 meaning the word has been found. If the word
 * is not there, 0 is returned instead. If there is an error, -1 is returned.
 */
int search(struct word_node *trie, char *word);

/**
 * @brief Remove a given word from a given trie.
 *
 * @param trie An existing trie
 * @param word A given word
 * @return On success, it returns 1 meaning the word has been removed. If the
 * word is not there, 0 is returned. If there is an error, -1 is returned.
 */
int delete(struct word_node *trie, char *word);

/**
 * @brief Deallocate a given trie.
 *
 * @param trie An existing trie
 * @return On success, it returns 1 meaning the trie has been deallocated. If
 * the trie is `NULL`, it returns 0. If there is an error, -1 is returned.
 *
 */
int deltrie(struct word_node *trie);

/**
 * @brief Copy an existing trie to a new trie
 *
 * @param other An existing trie
 * @return On success, it returns 1 meaning a new copied version of the given
 * trie has been created. If the given trie is `NULL`, 0 is returned. If there
 * is an error, -1 is returned instead.
 */
int copy(struct word_node *src, struct word_node **dest);

#endif // __TRIE_H
