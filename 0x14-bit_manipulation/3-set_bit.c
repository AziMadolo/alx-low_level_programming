#include "main.h"

/**

set_bit - Sets the value of a bit at a specified index to 1.

@n: Pointer to the number to modify.

@index: Index of the bit to set to 1.

Return: 1 on success, -1 on failure.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1UL;

if (index > 63)
return (-1);

mask <<= index;
*n |= mask;
return (1);
}
