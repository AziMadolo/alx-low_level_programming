#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: number to be printed in binary
 *
 * Description: This function prints the binary representation of a decimal number.
 *              It uses a bitwise shift and bitwise AND operations to extract the
 *              binary digits from the given number.
 *              The function assumes a 64-bit architecture.
 */
void print_binary(unsigned long int n)
{
    int i;
    unsigned long int mask = 1UL << 63;

    for (i = 0; i < 64; i++)
    {
        if (n & mask)
            _putchar('1');
        else
            _putchar('0');

        mask >>= 1;
    }
}
