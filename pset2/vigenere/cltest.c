#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    // check for the right amount of comand-line inputs
    
    if (argc != 2)
    {
        printf("Wrong number of inputs arguments\n");
        return 1;
    }
    
    string key = argv[1]; 
    int key_size = strlen(key);
    for (int i=0; i<key_size; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Non-alphabetic char are not permitted as key part\n");
            return 1;
        }    
    }

}