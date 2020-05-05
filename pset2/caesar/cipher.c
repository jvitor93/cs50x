#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
    char c, cipher;
    int k, cint,ciph_int;
    
    c = 'a';
    cint = (int)c;
    k = 2;
    ciph_int = (cint+k)%26;
    cipher = (char)ciph_int;
    
    printf("%c in int is %i\n", c, cint);
    printf("%i is char + key\n", ciph_int);
    printf("%c is %i, in ascii\n", cipher, ciph_int);
}