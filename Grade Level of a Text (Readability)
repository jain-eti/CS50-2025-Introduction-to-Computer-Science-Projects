#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

//**********PROTOTYPING************************************ */
void count_text_elements(string text);
void final_grade_print(int index);
int sentence = 0, word = 1, letter = 0;

//************MAIN PROGRAM************************* */

int main(void)
{

    string text = get_string("Text:");
    count_text_elements(text);
    int L = ((float) letter / word) *
            100; // average letters = letters/words, multiply by 100 for per 100 words
    int S = ((float) sentence / word) * 100;

    float letter_weight = 0.0588;
    float sentence_weight = 0.296;
    float constant = 15.8;
    float index_float =
        (letter_weight * L) - (sentence_weight * S) - constant; // Coleman-Liau index
    int index = round(index_float);
    final_grade_print(index);
}

//*******************USER DEFINED FUNCTIONS*********************** */
void count_text_elements(string text)
{
    int i = 0;
    while (text[i] != 0)
    {

        if (text[i] == '.' || text[i] == '!' ||
            text[i] == '?') // new sentence if ends with "." or "!" or "?"
        {
            sentence++;
        }
        else if (text[i] == ' ')
        {
            if (text[i - 1] == ' ' && i > 0) // no new word if two consecutive spaces
            {
                continue;
            }
            else
            {
                word++;
            }
        }
        else if (isalpha(text[i])) // isalpha is used to check for alphabets
        {
            letter++;
        }
        i++;
    }
}

void final_grade_print(int index)
{

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
