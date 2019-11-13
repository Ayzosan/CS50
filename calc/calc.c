// includes
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //check correcty argc
    if (argc != 4) {
        printf("Invalid command-line argument! usage: ./calc <number> <operand> <number>\n");
        return 1;
    }

    //check if argv[2] is appropriate operand
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/' && argv[2][0] != '%') {
        printf("Invalid operator!");
        return 1;
    }

    //get nums from argv
    float numone = atof(argv[1]);
    float numtwo = atof(argv[3]);

    //get operand from argv
    string operatorstring = argv[2];
    char operatorchar = operatorstring[0];

    //initialize result
    float result;
    int bigNum;

    //perform operation
    switch(operatorchar) {
        case '+' :
            result = numone + numtwo;
            break;
        case '-' :
            result = numone - numtwo;
            break;
        case 'x' :
            result = numone * numtwo;
            break;
        case '/' :
            result = numone / numtwo;
            break;
        case '%':
            bigNum = (int)(numone / numtwo);
            result = numone - (numtwo * bigNum);
    }

    //print result
    printf("%.6f\n", result);
}