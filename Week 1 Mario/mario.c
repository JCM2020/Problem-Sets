#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, j;
    int i = 0;

    /* Prompt user to input pyramid height,
    Repeat until an integer between 1 and 8 is chosen */

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    /* Nested for loop */

    for (i = 0; i < n; i++) /* Prints nested conditions then prints new line
                            i increments by 1
                            Repeats until i < n is false*/
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");    /*Blank space to push # to right alignment
                            j increments by 1
                            Each time j < n - i - 1, will print blank space
                            When j has increased so that j < n - i - 1 is false
                            Control passes to next line*/
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("#");    /* Right aligned pyramid
                            j increments by 1
                            Each time j < i +1 is true, will print #
                            When j has increased so that j < i + 1 is false
                            Control passes to next line*/
        }
        for (j = 0; j <= 1; j++)
        {
            printf(" ");   /* Forms double blank space between pyramids
                            j increments by 1
                            Each time j <= 1 is true, will print blank space
                            When j has increased so that j <= 1 is false
                            Control passes to next line*/
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("#");    /* Left-aligned pyramid
                            j increments by 1
                            Each time j < i +1 is true, will print #
                            When j has increased so that j < i + 1 is false
                            Control passes to next line*/
        }
        printf("\n");       /* Prints new line */
    }
}
