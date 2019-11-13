#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asking for height
    int height;
    do
    {
        printf("What should the height of the pyramid be \n ");
        height = get_int();
    }
    while (height < 0 || height > 23);


    //building pyramid
    for (int row = 0; row < height; row++)
    {
        for (int spaces = height - row; spaces > 1; spaces--)
        {
            printf(" ");
        }
        for (int hashtags = 0; hashtags < row + 1; hashtags++)
        {
            printf("#");
        }

        printf("  ");

        for (int hashtags = 0; hashtags < row + 1; hashtags++)
        {
            printf("#");
        }
        printf("\n");
    }









}