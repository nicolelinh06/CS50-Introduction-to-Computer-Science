#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(string plaintext, string key);
int validate(string text); // Use int instead of bool

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1; // Exit with an error code
    }

    // Check if key is valid
    if (validate(argv[1]) != 0)
    {
        return 1; // Exit if validation fails
    }

    string plaintext = get_string("plaintext: ");
    encrypt(plaintext, argv[1]); // Encrypt plaintext
    return 0;                    // Return success
}

int validate(string text)
{
    int len = strlen(text);

    // Check if length is 26 characters
    if (len != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1; // Failure
    }

    // Check for alphabetic characters and repeated characters
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check for non-alphabetic characters
        if (!isalpha(text[i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1; // Failure
        }

        // Check for repeated characters (case insensitive)
        for (int j = i + 1; j < len; j++)
        {
            if (toupper(text[i]) == toupper(text[j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1; // Failure
            }
        }
    }

    return 0; // Success
}

void encrypt(string plaintext, string keytext)
{
    char ciphertext[1000];       // Array to hold ciphertext
    int len = strlen(plaintext); // Get the length of the plaintext

    // Encrypting the plaintext
    for (int i = 0; i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(keytext[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(keytext[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i]; // Keep non-alphabetic characters
        }
    }
    ciphertext[len] = '\0'; // Null-terminate the ciphertext

    printf("ciphertext: %s\n", ciphertext); // Print the ciphertext
}