// Helper functions for the sort race

#include <cs50.h>
#include "helpers.h"

// Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    string stringa = "-a";
    string stringb = "-b";
    string stringr = "-r";
    string strings = "-s";
    if (strcmp(str, stringa) || strcmp(str, stringb)  || strcmp(str, stringr) || strcmp(str, strings))
    {
        return true;

    }
    else
    {
        return false;
    }
}

// Sorts array of n values using bubble sort
void bubble(int values[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                //swapping the values
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

// Sorts array of n values using selection sort
void selection(int values[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[minimum])
            {
                minimum = j;
            }
            if (minimum != i)
            {
                //swapping the values
                int temp = values[minimum];
                values[minimum] = values[i];
                values[i] = temp;
            }
        }
    }
}

// Sorts array of n values using insertion sort
void insertion(int values[], int n)
{
    int element;
    int j;
    for (int i = 1; i < n; i++)
    {
        element = values[i];
        j = i;
        while (j > 0 && values [j - 1] > element)
        {
            //inserting the values
            values[j] = values [ - 1];
            j = j - 1;
        }
        values[j] = element;
    }
}
