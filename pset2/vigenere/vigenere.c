#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char vigenere_cipher(char c, int key);

int main (int argc, string argv[])
{
    // check for the right amount of comand-line inputs
    
    if (argc != 2)
    {
        printf("Wrong number of inputs arguments\n");
        return 1;
    }
    
    // check key for non alphabetic input
    
    string key = argv[1]; 
    int key_size = strlen(key);
    for (int i=0; i<key_size; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Non-alphabetic char are not supported\n");
            return 1;
        }    
    }
    
    // convert key to lowercase
     for (int i=0; i<key_size; i++)
     {
         key[i]=tolower(key[i]);
     }
    
    printf("plaintext: ");
    string text = get_string(); // gets text from the user
    int size = strlen (text); // gets the string size
    printf("ciphertext: ");
    
    
    // print each char
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if(isalpha(text[i]))
        {
            printf ("%c",  vigenere_cipher(text[i], key[j%key_size]));
            j++;
        }
        else 
            printf("%c", text[i]);
    }
        printf("\n");
    
    return 0;
}




// Function to check an convert each char in the text to crypto form
// uses the char to be cryptpgraphed and a key[i], then returns the changed char.

char vigenere_cipher(char c, int key)
{
    char encrypted_char;
    // check if it is alphabetic, otherwise return unchanged
   
    if (islower(c)) // convert lowercase
    {
        encrypted_char = (c - 'a' + key - 'a')%26 + 'a';
        return encrypted_char;
    }
    else // convert uppercase
    {
        encrypted_char = (c - 'A' + key - 'a')%26 + 'A';
        return encrypted_char;
    }
}