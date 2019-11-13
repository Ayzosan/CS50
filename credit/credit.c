#include <cs50.h>
#include <stdio.h>

void print_brand(long long ccn);
void checkval(long long ccn);
int length(long long n);
bool checklength(int len);
bool checksum(long long ccn, int len);

int main(void)
{
    //Get cardnumber as longlong
    long long ccn;
    do
    {
        ccn = get_long_long("Your Credit card Number?: ");
    }
    while (ccn < 0);

    checkval(ccn);

}

void checkval(long long ccn)
{
    int len = length(ccn);
    if (!(checklength(len) && checksum(ccn, len)))
    {
        printf("INVALID\n");
        return;
    }
    //after checking validity print out brand of card
    print_brand(ccn);
}
//returns the length of the creditcard number
int length(long long n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

//check validity through length; returns false if invalid
bool checklength(int len)
{
    if (len == 13 || len == 15 || len == 16) // {] MISSING?
    {
        return true;
    }
    return false;
}

bool checksum(long long ccn, int len)
{
    int sum = 0;
    //loop through the ccn's length(i)
    for (int i = 0; i < len; i++, ccn /= 10)
    {
        //when i is even
        if (i % 2 == 0)
        {
            //simply add i to i
            sum += (ccn % 10);
        }
        //when i is odd
        else
        {
            //"split add" i to i ---- (18/10 = 1) + (18 % 10 = 8) <- HOW TO single out numbers#
            int digit = (2 * (ccn % 10));
            sum += ((digit / 10) + (digit % 10));
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

//AMEX   =   340 000 000 000 000 -   370 000 000 000 000
//MC     = 5 100 000 000 000 000 - 5 500 000 000 000 000
//VISA13 =     4 000 000 000 000 -     4 999 999 999 999
//Visa16 = 4 000 000 000 000 000 - 4 999 999 999 999 999

void print_brand(long long ccn)
{
    if ((ccn >= 340000000000000 && ccn < 350000000000000) || (ccn >= 370000000000000 && ccn < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if ((ccn >= 5100000000000000 && ccn < 5600000000000000))
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4000000000000 && ccn < 5000000000000) || (ccn >= 4000000000000000 && ccn < 5000000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}