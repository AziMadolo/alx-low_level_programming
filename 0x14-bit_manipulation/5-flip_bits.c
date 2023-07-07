#include "main.h"

/**
 * flip_bits - Counts the number of bits that need to be flipped
 * to transform one number into another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned int count = 0;
    unsigned long int exclusive = n ^ m;

    while (exclusive != 0)
    {
        count++;
        exclusive &= (exclusive - 1);
    }

    return count;
}
