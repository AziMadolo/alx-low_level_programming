#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i;
	unsigned long int mask = 1UL << 63;

	for (i = 0; i < 64; i++)
	{
		if ((n & mask) != 0)
		{
			_putchar('1');
		}
		else
		{
			if (i > 0)
				_putchar('0');
		}
		mask >>= 1;
	}

	if (n == 0)
		_putchar('0');
}
