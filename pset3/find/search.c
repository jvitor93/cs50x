#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    int n=10;
    int values[] = {1, 5, 7 , 8, 10, 11, 16, 36, 40, 41};
    int value = 36;
    
    for (int i=0; i<10; i++)
    {
        printf("%i ", values[i]);
    }
    
    int mid = floor(n/2);
    
    if (values[mid]==value)
    {
        return true;
    }
    else if (values[mid]>value)
    {
        int valuesn[n-mid-1];
        for (int i=0;i<mid;i++)
        {
            valuesn[i]=values[i];
            values=valuesn;
        }
    }
    
    
    
}