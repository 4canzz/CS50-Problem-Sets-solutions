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
        printf("\n");
    }
    return 0;
}

/*Problem to Solve
Toward the end of World 1-1 in Nintendo’s Super Mario Bros., Mario must ascend right-aligned pyramid of bricks,
as in the below.

screenshot of Mario jumping up a right-aligned pyramid

In a file called mario.c, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
But prompt the user for an int for the pyramid’s actual height, so that the program can also output shorter pyramids 
like the below:

  #
 ##
###
Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an int altogether.*/