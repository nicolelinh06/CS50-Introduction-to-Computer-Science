#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int height, row, column, space;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For row
    for (row = 0; row < height; row++)
    {
        // Align left-column
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // For column in the left
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("  ");

        // For column in the right
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("\n");
    }
}
