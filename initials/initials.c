#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get user input
    string s = get_string();
    //print out first character of input as upper
    printf("%c", toupper(s[0]));
    //prints characters after spaces in uppercase incase middle name and last name
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i + 1]));
        }
    }
    printf("\n");
}
