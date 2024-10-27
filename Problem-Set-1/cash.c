#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    int coins = 0;
    do
    {
        change = get_int("change owed (in cents): ");
    }
    while (change < 0);

    coins += change / 25;
    change %= 25;
    coins += change / 10;
    change %= 10;
    coins += change / 5;
    change %= 5;
    coins += change;

    printf("%i\n", coins);
    return 0;
}

/*Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). 
You’ll need to pay them their “change,” the amount leftover after paying fr the cost of the candy. When making
 change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out
(or annoy the customer!). In a file called cash.c in a folder called cash, implement a program in C that prints
the minimum coins needed to make the given amount of change, in cents, as in the below:

Change owed: 25
1
But prompt the user for an int greater than 0, so that the program works for any amount of change:

Change owed: 70
4
Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).*/