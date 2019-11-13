#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float temp = get_float("C: ");
    printf("%.1f\n", ((temp * 9) / 5) + 32);
}