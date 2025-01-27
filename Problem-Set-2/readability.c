#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[100000];
    printf("Text: \n");
    scanf("%[^\n]%*c", buffer);

    int letters = 0;
    int words = 0;
    int sentences = 0;
    int arraySize = strlen(buffer);
    for (int i = 0; i < arraySize; i++)
    {
        // letters = count_letters(text);
        if (isalpha(buffer[i]))
        {
            letters++;
        }
        // words = count_words(text);
        if (buffer[i] == ' ')
        {
            words++;
        }
        // sentences = count_sentences(text);
        if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')
        {
            sentences++;
        }
    }

    words++;

    double L = ((double) letters / (double) words) * 100;
    printf("L is %f\n", L);
    double S = ((double) sentences / (double) words) * 100;
    printf("S is %f\n", S);
    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("index is %f\n", index);

    if ((int) index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("%s%i\n", "Grade ", (int) round(index));
    }
}


/*So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading
 levels. Likewise, longer sentences probably correlate with higher reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. 
One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade 
level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in
 the text.*/