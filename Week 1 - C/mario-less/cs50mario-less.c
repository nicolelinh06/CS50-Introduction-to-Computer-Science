#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for height
    int height, row, column, z;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For row
    for (row = 0; row < height; row++)
    {
        // Align
        for (z = 0; z < height - row - 1; z++)
        {
            printf(" ");
        }

        // For column
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}