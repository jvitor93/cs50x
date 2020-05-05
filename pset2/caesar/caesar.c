#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char caesar_cipher(char c, int key);

int main (int argc, string argv[])
{
    // check for the right amount of in line inputs
    
    if (argc != 2)
    {
        printf("Wrong number of inputs arguments\n");
        return 1;
    }
    int key = atoi(argv[1]); // converts the key from string to int
    
    printf("plaintext: ");
    string text = get_string(); // gets text from the user
    int size = strlen (text); // gets the string size
    printf("ciphertext: ");
   
   
   // print each char  
    for (int i = 0; i < size; i++)
    {
        printf ("%c",  caesar_cipher(text[i], key));
    }
        printf("\n");
}


// Function to check an convert each char in the text to crypto form
// uses the char to be cryptpgraphed and a key, then returns the changed char.

char caesar_cipher(char c, int key)
{
    char encrypted_char;
    // check if it is alphabetic, otherwise return unchanged
    if (isalpha(c))
    {
        if (islower(c)) // convert lowercase
        {
            encrypted_char = (c - 'a' + key)%26 + 'a';
            return encrypted_char;
        }
        else // convert uppercase
        {
            encrypted_char = (c - 'A' + key)%26 + 'A';
            return encrypted_char;
        }
    }
    else 
        return c;
    
}