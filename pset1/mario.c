#include <cs50.h>
#include <stdio.h>


void print_spaces (int n);
void print_hashes (int n);

int main (void)
{
    int h;
   // Get a positive int from user between 0-23
    do
    {
       h = get_int("Height: ");
    }
    while (h < 0 || h > 23);

    // iteration for printing each line of the pyramid
    for (int i = 0; i < h; i++)
    {

       print_spaces(h-1-i); //print initial spaces in line i (left side)
       print_hashes(i+1); //print hashes in line i (left side)
       print_spaces(2); // print gap between the pyramid sides
       print_hashes(i+1); // print hashes on the right side
       printf("\n");
    }
}

// function for printing "n" spaces
void print_spaces (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

// function for printing "n" hashes
void print_hashes (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}