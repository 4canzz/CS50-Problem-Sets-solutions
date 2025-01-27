#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool isValid(int argc, string argv[]);
char encode(char plaintextindexvalue, string argv);
void substitute(string argv[]);

int main(int argc, string argv[])
{
    if (isValid(argc, argv))
    {
        substitute(argv);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

bool isValid(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]); i++)
            {

                if (!isalpha(argv[1][i]))
                {
                    printf("Key must contain 26 characters.\n");
                    return false;
                }

                for (int j = i + 1; j < strlen(argv[1]); j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return false;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
}

char encode(char plaintextindexvalue, string argv)
{
    const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < strlen(alpha); i++)
    {
        if (islower(plaintextindexvalue))
        {
            if (plaintextindexvalue == tolower(alpha[i]))
            {
                return tolower(argv[i]);
            }
        }
        else
        {
            if (plaintextindexvalue == toupper(alpha[i]))
            {
                return toupper(argv[i]);
            }
        }
    }
    return plaintextindexvalue;
}

void substitute(string argv[])
{
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                printf("%c", encode(tolower(plaintext[i]), argv[1]));
            }
            else
            {
                printf("%c", encode(toupper(plaintext[i]), argv[1]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

/*In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the 
alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text
(generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B 
(the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

In a file called substitution.c in a folder called substitution, create a program that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by 
providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.*/