#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: String containing the binary number.
 *
 * Return: The converted number as an unsigned integer, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		dec_val = (dec_val * 2) + (b[i] - '0');
	}

	return (dec_val);
}
