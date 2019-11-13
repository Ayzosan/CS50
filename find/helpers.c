// Helper functions

#include <cs50.h>

#include "helpers.h"

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = (n - 1);
    int mid = ((max + min) / 2);
    //binary search
    while (min <= max)
    {
        //if the searched for value is the middle we have found the number
        if (values[mid] == value)
        {
            return true;
        }
        //if the middle is bigger then the searched for number
        else if (values[mid] > value)
        {
            max = (mid - 1);
            mid = ((max + min) / 2);
        }
        //if the middle is smaller then the searched for number
        else if (values[mid] < value)
        {
            min = (mid + 1);
            mid = ((max + min) / 2);
        }
        //if number can't be found
        else
        {
            return false;
        }
    }
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    //creating variables for moving
    int element;
    int j;
    //insertion sort
    for (int i = 1; i < n; i++)
    {
        element = values[i];
        j = i;

        while (j > 0 && values[j - 1] > element)
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = element;
    }
}
