#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int code[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int scrabble(string word, int code[]); // user defined function

int main(void)
{
    // getting words from the user
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int sum1 = scrabble(p1, code);
    int sum2 = scrabble(p2, code);

    // checking who won based on score
    if (sum1 < sum2)
    {
        printf("Player 2 wins!\n");
    }
    else if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int scrabble(string word, int score[])
{
    int sum = 0;
    int length = strlen(word); // length of the word

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        { // omitting special characters and spaces in score
            int index = toupper(word[i]) -
                        'A'; // index for the char by ASCII code for letter- ASCII code for A
            sum += score[index];
        }
    }

    return sum;
}
