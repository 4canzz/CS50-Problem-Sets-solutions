#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_score(string word);

int main(void)
{
    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    int score_1 = calculate_score(word_1);
    int score_2 = calculate_score(word_2);

    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int calculate_score(string word)
{
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}


/*In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values
of each letter in the word.

A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10
For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point,
 the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.

In a file called scrabble.c in a folder called scrabble, implement a program in C that determines the winner of a short
Scrabble-like game. Your program should prompt for input twice: once for “Player 1” to input their word and once for
“Player 2” to input their word. Then, depending on which player scores the most points, your program should either print
“Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).*/