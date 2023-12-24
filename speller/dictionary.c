#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Number of words in the dictionary
int dict_size = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");

    // Check if the file opened successfully
    if (dict_pointer == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Initialize an array to store the next word
    char next_word[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false; // Memory allocation failed
        }

        // Copy the word into the node
        strcpy(n->word, next_word);

        // Hash the word to obtain the hash value
        int hash_value = hash(next_word);

        // Insert the node into the hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;

        // Increment the dictionary size
        dict_size++;
    }

    // Close the file
    fclose(dict_pointer);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // This hash function adds the ASCII values of all characters in the word together
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N; // Return the hash value within the range of the hash table size
}

// Returns the number of words in the dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Returns true if the word is in the dictionary, else false
bool check(const char *word)
{
    // Hash the word to obtain the hash value
    int hash_value = hash(word);

    // Access the linked list at that index in the hash table
    node *n = table[hash_value];

    // Traverse the linked list, looking for the word (case-insensitive comparison)
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true; // Word found in the dictionary
        }
        n = n->next;
    }

    return false; // Word not found
}

// Unloads the dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over the hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign the cursor
        node *n = table[i];

        // Loop through the linked list
        while (n != NULL)
        {
            // Make a temporary variable equal to the cursor
            node *tmp = n;

            // Move the cursor to the next element
            n = n->next;

            // Free the temporary variable
            free(tmp);
        }

        // Check if the end of the linked list is reached and it's the last index
        if (n == NULL && i == N - 1)
        {
            return true; // Unloading successful
        }
    }

    return false; // Unloading failed
}