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

