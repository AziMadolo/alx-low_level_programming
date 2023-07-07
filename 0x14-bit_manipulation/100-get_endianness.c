#include "main.h"
#include <stdint.h>

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	uint16_t num = 1;
	uint8_t *byte_ptr = (uint8_t *)&num;

	return (*byte_ptr == 1);
}
