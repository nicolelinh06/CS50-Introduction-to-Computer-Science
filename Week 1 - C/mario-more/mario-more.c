#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int height, row, column, space;
    do
    {
        printf("Height: ");
        scanf( " %i", &height);  // Use & to store input in the height variable
    }
    while (height < 1 || height > 8);  // Loop continues if height is out of range

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

    return 0;
}