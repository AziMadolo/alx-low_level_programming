#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;
	int endianness;

	if (*c)
		endianness = 1;  /* Little Endian */
	else
		endianness = 0;  /* Big Endian */

	return (endianness);
}
