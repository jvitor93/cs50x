#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    //get user input
    string full_name = get_string();
    int size = strlen(full_name);
    
    // check if the 0th char is not a space, the print it
    if (full_name[0]!=' ')
        printf("%c", toupper(full_name[0]));

    // check the others char in the string
    // and then print the ones after the spaces
    for (int i = 1; i < size; i++)
    {
        if (full_name[i - 1] == ' ' && full_name[i]!= ' ')
            printf("%c", toupper(full_name[i]));
    }
    printf("\n");
}