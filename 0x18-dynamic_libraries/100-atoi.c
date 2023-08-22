#include "main.h"

/**
 * _atoi - Custom string to integer conversion function.
 * @s: Input string to be converted.
 *
 * Return: The integer converted from the input string.
 */
int _atoi(char *s)
{
    int sign = 1; // Initialize the sign of the number as positive
    unsigned int num = 0; // Initialize the resulting number as an unsigned integer

    do {
        if (*s == '-') {
            sign *= -1; // Toggle the sign if a minus sign is encountered
        } else if (*s >= '0' && *s <= '9') {
            num = num * 10 + (*s - '0'); // Build the integer digit by digit
        } else if (num > 0) {
            break; // Stop parsing if non-digit characters come after digits
        }
    } while (*s++);

    return (num * sign); // Return the final result with the appropriate sign
}
