#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_first_two_digits(long credit);
int get_digit_count(long credit);
bool validate_luhn(long credit);
void validate_card_type(int count, int first_two_digits);

int main(void)
{
    long credit;
    do
    {
        credit = get_long("Number: ");
    }
    while (credit <= 0);

    // Get card length and first two digits
    int count = get_digit_count(credit);
    int first_two_digits = get_first_two_digits(credit);

    // Check if credit card length is valid
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Validate using Luhn's Algorithm
    if (!validate_luhn(credit))
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine and print the card type
    validate_card_type(count, first_two_digits);
}

// Function to capture the first two digits
int get_first_two_digits(long credit)
{
    while (credit >= 100)
    {
        credit /= 10;
    }
    return credit;
}

// Function to count the digits in the credit card number
int get_digit_count(long credit)
{
    int count = 0;
    while (credit > 0)
    {
        credit /= 10;
        count++;
    }
    return count;
}

// Function to validate the credit card using Luhn's Algorithm
bool validate_luhn(long credit)
{
    int total_sum = 0;
    int num_pos = 0;

    while (credit > 0)
    {
        int digit = credit % 10;
        if (num_pos % 2 == 1) // Double every second digit from the right
        {
            int luhn_1 = digit * 2;
            if (luhn_1 > 9)
            {
                total_sum += (luhn_1 % 10) + (luhn_1 / 10); // Sum the digits
            }
            else
            {
                total_sum += luhn_1;
            }
        }
        else
        {
            total_sum += digit; // Sum the other digits, not x2
        }

        credit /= 10;
        num_pos++;
    }

    return total_sum % 10 == 0; // Valid if sum is divisible by 10
}

// Function to determine and print the card type
void validate_card_type(int count, int first_two_digits)
{
    if (count == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && (first_two_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}