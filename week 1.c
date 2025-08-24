#include <cs50.h>
#include <stdio.h>

//*************** PROTOTYPING **************************
int length_of_long(long cnum);
int checking_company(int len, long cnum);

//**************** MAIN CODE ***************************

int main(void)
{
    int index = 0, sum1 = 0, sum = 0;
    long cnum = get_long("Enter credit card number: ");

    int len = length_of_long(cnum);

    long copy = cnum; // saving the original cnum for further uses
    while (copy > 0)
    {
        int digit = copy % 10; // using remainder to find the last digit

        if (index % 2 == 0) // every other digit starting from last number (index 0,2,4..)
        {
            sum1 += digit;
        }
        else // every other digit starting from second to last number (index 1,3,5..)
        {
            digit *= 2;
            if (digit > 9) // adding the individual digits of cnum digit*2
            {
                sum += (digit % 10) + (digit / 10);
            }
            else // if on multiplying by 2, the digit remains ones place, add as is
            {
                sum += digit;
            }
        }

        index++;    // increment index
        copy /= 10; // cnum changes to it's quotient produced by /10
    }

    int final_sum = sum1 + sum;

    if (len > 12 && len < 17)
    {
        if (final_sum % 10 != 0) // checking luhn's algorithm
        {
            printf("INVALID\n");
            return 0;
        }
        int flag = checking_company(len, cnum);

        if (flag == 1) // if it doesn't satisfy the condition for VISA, MASTERCARD and AMEX
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// *************************** USER DEFINED FUNCTIONS ************************

int length_of_long(long cnum)
{
    int len = 0;
    while (cnum)
    {
        cnum = cnum / 10; // cnum changes to it's quotient when divided by 10
        len++;
    }
    return len;
}

int checking_company(int len, long cnum)
{
    int flag = 0;

    while (cnum >= 100)
    {
        cnum /= 10; // cnum is replaced by it's quotient until only 2 digits remain
    }

    int first_two = cnum;       // first two digits of cnum to check for MASTERCARD and AMEX
    int first = first_two / 10; // first digit to check for VISA

    if (first == 4 && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else if ((first_two == 34 || first_two == 37) && len == 15)
    {
        printf("AMEX\n");
    }
    else if ((first_two >= 51 && first_two <= 55) && len == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        flag = 1;
    }
    return flag;
}
