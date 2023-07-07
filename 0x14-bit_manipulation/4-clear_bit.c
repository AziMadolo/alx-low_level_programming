#include "main.h"

/**
 * clear_bit - Sets the value of a specified bit to 0.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to clear.
 *
 * Return: 1 for success, -1 for failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index;
	*n &= ~mask;

	return (1);
}
