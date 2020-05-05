/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    if (value<0)
    return false;
    // intialization of parameters
    int last=n-1, first = 0, mid;
    
    // iterate to cut array in half each time
    do 
    {
        // set the middle value iteratively (each time, since first and last value can change)
        mid = (last+first)/2; 
        
        //if value in the middle is greater than we're looking, change to the left half
        if (values[mid]>value) 
        {
            last = mid;
        }
        //if value in the middle is less than we're looking, change to the right half
        else if (values[mid]<value)
        {
            first=mid;
        }
        else // if it is equal
        {
           return true; 
        }
    }
    while (last-first>1);
    
    // evaluate the residual first and last values
    if (values[first]==value||values[last]==value)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i, j, greater, lower; //declaring variables
    
    //bubble sort
    
    // iterate the check inside until all the values have been swaped
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
           // chech pair of values and swap if not in order
            if (values[j]>values[j+1])
            {
                greater=values[j];
                lower=values[j+1];
                values[j]=lower;
                values[j+1]=greater;
            }
        }
    }
}
