#include <cs50.h>
#include <stdio.h>
#include <math.h>

int coin_counter = 0;
int count (int n, int coin);

int main (void)
{
    float dl; 
    int rem, cents;
    
    // Asks for the change value from the user while input is negative
    do 
    {
       printf("Change ($): ");
       dl = get_float();
    } 
    while (dl < 0);
  
    // convert the dolar value to cents and format as (int)
    cents = round (dl*100);

    // counts how many of each coin is used
    
    rem = count(cents, 25); // count quarters
    rem = count(rem, 10);   // count dimes
    rem = count(rem, 5);    // count neckels
    rem = count(rem, 1);    // count pennies

    // prints the total number of coins needed
    printf("%i\n", coin_counter);

}

/* Given a total value "val" in cents, and coin of value "coin"
 * this function adds the max number of this coin to be use to pay that value
 * returns the remainer value.
 */ 
int count (int val, int coin)
{
    while (val >= coin)
    {
        val = val - coin;
        coin_counter++;
    }
    return val;
}