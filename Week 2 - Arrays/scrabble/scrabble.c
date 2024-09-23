#include <ctype.h>
#include <stdio.h>

int point_counter(const char *word); // const meaning read-only
void compare_point(int count1, int count2);

int main(void)
{
    char word1[100]; // Buffer to hold player 1's input
    char word2[100]; // Buffer to hold player 2's input

    printf("Player 1: ");
    scanf("%s", word1); // Read a string for player 1

    printf("Player 2: ");
    scanf("%s", word2); // Read a string for player 2

    int count1 = point_counter(word1); // Calculate points for player 1
    int count2 = point_counter(word2); // Calculate points for player 2

    compare_point(count1, count2); // Compare points
}

int point_counter(const char *word)
{
    int count = 0; // Counter for points

    // Iterate through the string until the null terminator
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = toupper(word[i]); // Convert to uppercase for comparison

        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
            c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
        {
            count++;
        }
        else if (c == 'D' || c == 'G')
        {
            count += 2;
        }
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
        {
            count += 3;
        }
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        {
            count += 4;
        }
        else if (c == 'K')
        {
            count += 5;
        }
        else if (c == 'J' || c == 'X')
        {
            count += 8;
        }
        else if (c == 'Q' || c == 'Z')
        {
            count += 10;
        }
    }
    return count; // Return total points for the word
}

void compare_point(int count1, int count2)
{
    if (count1 > count2)
    {
        printf("Player 1 wins!\n");
    }
    else if (count1 < count2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}