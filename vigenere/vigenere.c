#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>



int main(int argc, string argv[])
{
    //Checking correctness of command-line arguments
    if (argc != 2)
    {
        printf("Usage: <program> <keyword> ('key must be a word')\n");
        return 1;
    }
    else
    {
        for (int i = 0, keylen = strlen(argv[1]); i < keylen; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: <program> <keyword> ('key cant contain numbers'\n");
                return 1;
            }
        }
    }

    //asking for Plaintext
    string plaintext = get_string("Plaintext: ");

    //typecasting argv key to int
    string key = argv[1];

    //print out cypfertext
    printf("ciphertext: ");

    for (int i = 0, j = 0, pltlen = strlen(plaintext), klen = strlen(key); i < pltlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            //converting uppercase letters
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'A') + toupper(key[j]) - 'A') % 26) + 'A');
                j = (j + 1) % klen;
            }
            //converting lowercase letters
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'a') + toupper(key[j]) - 'A') % 26) + 'a');
                j = (j + 1) % klen;
            }
        }
        //plainly printing out nonalphas
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}