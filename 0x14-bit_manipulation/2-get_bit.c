#include "main.h"

/**
 * get_bit - retrieves the value of a specific bit at an index in a decimal number
 * @n: the number to search
 * @index: the index of the bit
 *
 * Return: the value of the bit at the given index, or -1 if the index is out of range
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}
