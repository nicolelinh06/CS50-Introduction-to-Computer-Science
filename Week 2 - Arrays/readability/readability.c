#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Input from user
    char text[1000]; // Buffer for user input
    printf("Text: ");
    scanf("%[^\n]", text); // Read a line of input until newline

    // Count letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate and print the grade level
    int index = calculate_index(letters, words, sentences);

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
        printf("Grade %i\n", index);
    }

    return 0;
}

// Function to count letters in the text
int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count words in the text
int count_words(const char *text)
{
    int count = 1; // Start with 1 because the first word isn't preceded by a space
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

// Function to count sentences in the text
int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

// Function to calculate Coleman-Liau index
int calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;   // Letters per 100 words
    float S = (float) sentences / words * 100; // Sentences per 100 words
    return round(0.0588 * L - 0.296 * S - 15.8);
}
