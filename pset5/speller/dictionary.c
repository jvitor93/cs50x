// Implements a dictionary's functionality
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Creating a hashtable
sllnode *hashtable[SIZE];
// Word counter
int wcounter = 0;


// Returns true if word is in dictionary else false
bool check(const char *data)
{
    unsigned char word[LENGTH + 1];
    strcpy((char *)word, data);
    
    int key = hash(strlwr(&word[0])) % SIZE;
    sllnode *trav = hashtable[key];
    
    while (trav != NULL)
    {
        if (strcasecmp((const char *)(trav->word), (const char *) word) == 0)
        {
            return true;   
        }
        trav = trav->next;
    }
    
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Memory Allocation each node of the hashtable
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = malloc(sizeof(sllnode));
        strcpy(hashtable[i]->word, "");
        hashtable[i]->next = NULL;
    }
    // Open dictionary file for reading
    FILE *inpt = fopen(dictionary, "r");
    if (inpt == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 2;
    }
    
    // Variable to store a word
    unsigned char word[LENGTH + 1];

    // Populate the hashtable with random words
    while (fscanf(inpt, "%s", word) != EOF)  // iterate through file
    {

        sllnode *new_node = malloc(sizeof(sllnode));
        if (new_node == NULL)
        {
            printf("Could not alloc memory for new node\n");
            break;
        }
        // insert the word into the new node
        strcpy(new_node->word, (const char *)word);
        wcounter++;
        
        // get the word key to input into the hashtable
        int key = hash(&word[0]) % SIZE;
        
        // Change the head of the list to be the new node
        new_node->next = hashtable[key];
        hashtable[key] = new_node;
    }
    
    // Close file
    fclose(inpt);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wcounter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through each index of hashtable
    for (int i = 0; i < SIZE; i++)
    {
        destroy(hashtable[i]);
    }
    return true;
}

// Hash function djb2 - http://www.cse.yorku.ca/~oz/hash.html
unsigned int 
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;    /* hash * 33 + c */
    }
    return hash;
}


void destroy(sllnode *list)
{
    // Base case
    if (list == NULL)
    {
        return;
    }
    
    // Recursive case
    destroy(list->next);
    free(list);
}
// Converts a string to lowercase
unsigned char *strlwr(unsigned char *s)
{
    unsigned char *t = s;

    if (!s)
    {
        return 0;
    }

    while (*t != '\0')
    {
        if (*t >= 'A' && *t <= 'Z')
        {
            *t = *t + ('a' - 'A');
        }
        t++;
    }

    return s;
}