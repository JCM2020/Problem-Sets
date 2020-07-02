#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Function gets the value of 10 to the power of n
long ten(int n);

int main(void)
{
    int cardtypenumber;

    // Prompts user to input card number
    long card = get_long("Number: ");

    // Numbers with fewer than 13 and greater than 16 digits will return as invalid
    if (card > 9999999999999999 || card <= 999999999999)
    {
        printf("INVALID\n");
    }

    /*  Isolating card digits using modulo and division,
        An integer != 10 divided by 10 will leave a single digit remainder, in the ones' value column
        An integer > 100 divided by 100 will leave a double digit remainder, in the ones' and tens' columns
        Divide that figure by 10 to isolate the digit in the tens' column
        Increase the modulo and division amount by powers of 10 (10, 100, 1000, 10,000) to get each digit */

    int last           = card % ten(1);
    int secondlast     = card % ten(2) / ten(1);
    int thirdlast      = card % ten(3) / ten(2);
    int fourthlast     = card % ten(4) / ten(3);
    int fifthlast      = card % ten(5) / ten(4);
    int sixthlast      = card % ten(6) / ten(5);
    int seventhlast    = card % ten(7) / ten(6);
    int eighthlast     = card % ten(8) / ten(7);
    int ninthlast      = card % ten(9) / ten(8);
    int tenthlast      = card % ten(10) / ten(9);
    int eleventhlast   = card % ten(11) / ten(10);
    int twelfthlast    = card % ten(12) / ten(11);
    int thirteenthlast = card % ten(13) / ten(12);
    int fourteenthlast = card % ten(14) / ten(13);
    int fifteenthlast  = card % ten(15) / ten(14);
    int sixteenthlast  = card % ten(16) / ten(15);

    /*  Each assigned a variable defined in relation to the last digit
        Means same variables can be used for card numbers of different length,
        leaving off the furthest-from-last variables for shorter numbers  */

    // AMEX - if loop to only consider only 15 digit card numbers
    if (card > 99999999999999 && card <= 999999999999999)
    {
        /*  Creating an array called digits, undefined quantity in array
            Applying Luhn's algoritihm to multiply by 2 every second digit starting from the second last */
        int digits [] = {(secondlast * 2), (fourthlast * 2), (sixthlast * 2), (eighthlast * 2),
                         (tenthlast * 2), (twelfthlast * 2), (fourteenthlast * 2)
                        };

        /*  Adding value of each digit's numbers, int defined as sumdigits
            Couldn't figure out how to do this
            Found info on stack overflow in an answer from Arpit Seth
            https://stackoverflow.com/questions/55038757/c-language-add-products-digits-i-e-not-the-products-themselves */

        int sumdigits = 0;

        int length = sizeof(digits) / sizeof(digits[0]);

        for (int x = 0; x < length; x++)
        {
            while (digits[x])
            {
                sumdigits += digits[x] % 10;
                digits[x] /= 10;
            }
        }

        // Continuing Luhn's algorithm, adding every second digit, starting from the last, int defined as sumtwo
        int sumtwo = (last) + (thirdlast) + (fifthlast) + (seventhlast) + (ninthlast)
                     + (eleventhlast) + (thirteenthlast) + (fifteenthlast);

        int sumthree = sumdigits + sumtwo;

        // If the sum of sumdigits and sumtwo, when divided by 10, has a remainder of 0 the card number is valid
        if (sumthree % 10 == 0)
        {
            // Divide card number until cardtypenumber is two digits
            do
            {
                cardtypenumber = card / ten(13);
            }
            while (cardtypenumber > ten(2));

            if (cardtypenumber == 34 || cardtypenumber == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // If sumthree, when divided by 10, does not have a remainder of 0, card number is invalid
        else if (sumthree % 10 != 0)
        {
            printf("INVALID\n");
        }
    }

    //  MASTERCARD/VISA - loop to only consider 16 digit numbers
    /*  This section, and the VISA only section after this follow the same logic applied in the AMEX section
        Main difference is one more figure used in digits array*/
    if (card > 999999999999999 && card <= 9999999999999999)
    {
        int digits [] = {(secondlast * 2), (fourthlast * 2), (sixthlast * 2), (eighthlast * 2),
                         (tenthlast * 2), (twelfthlast * 2), (fourteenthlast * 2), (sixteenthlast * 2)
                        };

        int sumdigits = 0;

        int length = sizeof(digits) / sizeof(digits[0]);

        for (int x = 0; x < length; x++)
        {
            while (digits[x])
            {
                sumdigits += digits[x] % 10;
                digits[x] /= 10;
            }
        }

        int sumtwo = (last) + (thirdlast) + (fifthlast) + (seventhlast) + (ninthlast) +
                     (eleventhlast) + (thirteenthlast) + (fifteenthlast);

        int sumthree = sumdigits + sumtwo;

        if (sumthree % 10 == 0)
        {
            // Divide card number until cardtypenumber is two digits
            do
            {
                cardtypenumber = card / ten(14);
            }
            while (cardtypenumber > ten(2));

            // If two digits are between 51 and 55, card is Mastercard
            if (cardtypenumber >= 51 && cardtypenumber <= 55)
            {
                printf("MASTERCARD\n");
            }
            // If when divided by 10, the remaining digit equals 4, card is VISA
            else if (cardtypenumber / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (sumthree % 10 != 0)
        {
            printf("INVALID\n");
        }
    }

    // VISA - if loop to consider only numbers with 13 digits

    if (card > 999999999999 && card <= 9999999999999)
    {
        int digits [] = {(secondlast * 2), (fourthlast * 2), (sixthlast * 2),
                         (eighthlast * 2), (tenthlast * 2), (twelfthlast * 2)
                        };

        int sumdigits = 0;

        int length = sizeof(digits) / sizeof(digits[0]);

        for (int x = 0; x < length; x++)
        {
            while (digits[x])
            {
                sumdigits += digits[x] % 10;
                digits[x] /= 10;
            }
        }

        int sumtwo = (last) + (thirdlast) + (fifthlast) + (seventhlast) + (ninthlast) +
                     (eleventhlast) + (thirteenthlast) + (fifteenthlast);

        int sumthree = sumdigits + sumtwo;

        if (sumthree % 10 == 0)
        {
            // Divide card number until cardtypenumber is one digit
            do
            {
                cardtypenumber = card / ten(12);
            }
            while (cardtypenumber > ten(1));

            if (cardtypenumber == 4)
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID");
        }
    }
}

// Function to get value of 10 to the power of n
long ten(int n)
{
    long i;
    i = pow(10, n);
    return i;
}
