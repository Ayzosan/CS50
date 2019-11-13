#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float owedchange;

    //Asks user for how much change is owed
    do
    {
        printf("How much change are you owed in $: ");
        owedchange = get_float();
    }
    while (owedchange < 0.0);

    //Converting owedchange into integer=owedchangeint
    int owedchangeint = round(owedchange * 100);

    //Calculating number of coins needed
    //American coin names and value
    //quarters = .25
    //dimes = .10
    //nickles = 5
    //pennies = 1

    int quarters = owedchangeint / 25;
    int dimes = (owedchangeint % 25) / 10;
    int nickles = (owedchangeint % 25 % 10) / 5;
    int pennies = (owedchangeint % 25 % 10 % 5) / 1;

    //Addin above calculated coins together
    int total = quarters + dimes + nickles + pennies;


    printf("%d\n", total);


}