#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(const char *plaintext, const char *key);
int validate(const char *text); // Use int instead of bool

int main(int argc, char *argv[])
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

    char plaintext[1000];
    printf("plaintext: ");
    scanf(" %[^\n]", plaintext); // Read until newline
    encrypt(plaintext, argv[1]); // Encrypt plaintext
    return 0;                    // Return success
}

int validate(const char *text)
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

void encrypt(const char *text, const char *keytext)
{
    char ciphertext[1000]; // Array to hold ciphertext
    int j = 0;             // Counter for ciphertext

    // Encrypting the plaintext
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
        {
            ciphertext[j++] =
                toupper(keytext[text[i] - 'A']); // j++ increments j to 1 for the next loop
        }
        else if (islower(text[i]))
        {
            ciphertext[j++] = tolower(keytext[text[i] - 'a']);
        }
        else
        {
            ciphertext[j++] = text[i]; // Keep non-alphabetic characters
        }
    }
    ciphertext[j] = '\0'; // Null-terminate the ciphertext

    printf("ciphertext: %s\n", ciphertext); // Print the ciphertext
}