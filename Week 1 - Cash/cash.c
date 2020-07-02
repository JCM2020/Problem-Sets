#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;   /* Define change as float */
    int cents;      /*Define cents as integer*/
    int coins = 0;  /*Define coins as integer, set value to 0*/

    /* Prompt user to input change owed,
    Repeat until positive number chosen*/

    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    /* Multiply change by 100 to get an integer in cents*/

    cents = round(change * 100);

    /* These four conditionals operate in the following way
    While cents is greater/equal to the chosen number
    Deduct that number from cents and increment coins by 1
    When cents is lesser than the chosen number
    Control passes to the next line*/

    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    /* Display the total amount of coins */

    printf("%d\n", coins);
}