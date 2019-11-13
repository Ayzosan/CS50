#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
  // make sure command line input correct.
  if (argc != 2)
  {
      printf("Command line arguments can't be greater or lower then 2\n");
      return 1;
  }
    // get a valid key = k and conert to int
    int key = atoi(argv[1]);


    //get plaintext
    string(plaintext) = get_string("Plaintext : ");

    //convert plaintext and keeping upper/lowercase in mind
    int i;
    int lengthP;

    printf("ciphertext: ");
    for (i = 0, lengthP = strlen(plaintext); i < lengthP; i++)
    {
        if (isalpha(plaintext[i]))
        {
            //change uppercase letters
            if (isupper(plaintext[i]))
            {

                printf("%c", (((plaintext[i] - 'A') + key) % 26) + 'A');

            }

            //change lowercase letters
            if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'a') + key) % 26) + 'a');
            }

        }

        //rest
        else
        {
        printf("%c", (plaintext[i]));
        }
    }

    printf("\n");
}