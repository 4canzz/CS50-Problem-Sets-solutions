#include <cs50.h>
#include <math.h>
#include <stdio.h>

int cardLength(long cardNumber)
{
    int length = 0;
    while (cardNumber > 0)
    {
        cardNumber /= 10;
        length++;
    }
    return length;
}

bool checksum(long cardNumber)
{
    int checksum = 0;
    bool doubleDigit = false;
    while (cardNumber > 0)
    {
        int digit = cardNumber % 10;
        cardNumber /= 10;

        if (doubleDigit)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        checksum += digit;
        doubleDigit = !doubleDigit;
    }

    return checksum % 10 == 0;
}

int main(void)
{
    long cardNumber;

    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    int Cardlength = cardLength(cardNumber);
    long firstTwoDigits = cardNumber / (long)pow(10, Cardlength - 2);
    long firstDigit = cardNumber / (long)pow(10, Cardlength - 1);

    if (checksum(cardNumber) && ((Cardlength >= 13) && (Cardlength <=16)))
    {
        if ((Cardlength == 13 || Cardlength == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (Cardlength == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (Cardlength == 16 && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

/*A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used 
to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit 
numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique
cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55
(they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a
mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query
a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more 
rigorous checks.

In a file called credit.c in a folder called credit, implement a program in C that checks the validity of a given credit card number.*/