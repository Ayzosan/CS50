// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths (duration)
int duration(string fraction)
{
    //fraction = X/Y
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int z = ((x * 8) / y);
    return z;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //parsing string into note and octave
    char N = note[0];
    int octave = note[strlen(note) - 1] - '0';

    int semitone;
    if (N == 'C')
    {
        semitone = 1;
    }
    if (N == 'D')
    {
        semitone = 3;
    }
    if (N == 'E')
    {
        semitone = 5;
    }
    if (N == 'F')
    {
        semitone = 6;
    }
    if (N == 'G')
    {
        semitone = 8;
    }
    if (N == 'A')
    {
        semitone = 10;
    }
    if (N == 'B')
    {
        semitone = 12;
    }
    if (note[1] == '#')
    {
        semitone ++;
    }
    if (note[1] == 'b')
    {
        semitone --;
    }
    //calculating frequencies
    float freq = 440 * (powf(2, (semitone - 10) / (float)12));

    return round(freq * (powf(2, (octave - 4))));
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    string rest = "";
    if (strcmp(s, ""))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
