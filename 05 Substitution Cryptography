#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) // for input in command line
{
    if (argc == 2) // if only file name and key is provided
    {
        string key = argv[1];
        if (strlen(key) != 26) // key must only be 26 chars
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }

        for (int j = 0; j < 26; j++) // key should not have any special characters/ numbers
        {
            if (isalpha(key[j]) == false)
            {
                printf("Invalid key\n");
                return 1;
            }
            for (int k = j + 1; k < 26;
                 k++) // to ensure no duplicate characters such that key[i] != key[i+1]
            {
                if (tolower(key[j]) == tolower(key[k]))
                {
                    printf("Invalid key");
                    return 1;
                }
            }
        }

        string plaintext = get_string("plaintext: ");
        int n = strlen(plaintext);
        char ciphertext[n + 1]; // +1 for '\0'

        for (int i = 0; i < n; i++)
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = toupper(key[plaintext[i] - 'A']);
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i] = tolower(key[plaintext[i] - 'a']);
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }

        ciphertext[n] = '\0'; // end the string
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n"); // if no. of arguments is not 2
        return 1;
    }
}
