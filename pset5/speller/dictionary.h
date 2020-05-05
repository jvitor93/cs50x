// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define SIZE 130000

// Defining slingle linked list structure
typedef struct sllist
{
    char word[LENGTH + 1];
    struct sllist *next;
}
sllnode;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
unsigned int hash(unsigned char *str);
void destroy(sllnode *list);
unsigned char *strlwr(unsigned char *s);

#endif // DICTIONARY_H
