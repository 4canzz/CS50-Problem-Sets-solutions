#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

/*Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

screenshot of Mario jumping over adjacent pyramids

In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

   #  #
  ##  ##
 ###  ###
####  ####
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.*/