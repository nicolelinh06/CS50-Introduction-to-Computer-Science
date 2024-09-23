#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {
    1,  3, 3, 2, 1, 4, 2, 4, 1, 8, // A-I
    5,  1, 3, 1, 1, 3,             // J-O
    10, 1, 1, 1, 1, 4, 4, 8, 4, 10 // P-Z
};

// Function prototypes
int compute_score(string word);             // Calculates the score for a given word
void compare_point(int score1, int score2); // Compares the scores of two players

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: "); // Prompt for Player 1's word
    string word2 = get_string("Player 2: "); // Prompt for Player 2's word

    // Calculate scores for both words
    int score1 = compute_score(word1); // Compute score for Player 1
    int score2 = compute_score(word2); // Compute score for Player 2

    // Compare and print the result based on scores
    compare_point(score1, score2); // Compare points and announce the winner
}

int compute_score(string word)
{
    // Calculate and return the score for the given word
    int length = strlen(word); // Get the length of the word
    int score = 0;             // Initialize score to 0

    // Loop through each character in the word
    for (int i = 0; i < length; i++)
    {
        // If the character is uppercase
        if (isupper(word[i]))
        {
            // Calculate score using the uppercase letter's index in POINTS
            score += POINTS[word[i] - 'A'];
        }
        // If the character is lowercase
        else if (islower(word[i]))
        {
            // Calculate score using the lowercase letter's index in POINTS
            score += POINTS[word[i] - 'a'];
        }
    }
    return score; // Return the total score for the word
}

void compare_point(int score1, int score2)
{
    // Print the winner based on the scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n"); // Player 1 has a higher score
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n"); // Player 2 has a higher score
    }
    else
    {
        printf("Tie!\n"); // Both players have the same score
    }
}