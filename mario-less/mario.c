#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //asking for height
    do
    {
        printf("How high should marios pyramid be? \n");
        height = get_int();
    }
    while (height < 0 || height > 23);

    //building pyramid
    for (int rows = 0; rows < height; rows++)
    {
        for (int spaces = height - rows; spaces > 1; spaces--)
        {
            printf(" ");
        }
        for (int hashtags = 0; hashtags < rows + 2; hashtags++)
        {
            printf("#");
        }
        printf("\n");
    }



}