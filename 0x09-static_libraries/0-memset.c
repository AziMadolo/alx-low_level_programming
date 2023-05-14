#include "main.h"
#include <stddef.h>

/**
 * _memset - Fills a block of memory with a specific value.
 * @s: starting address of memory to be filled
 * @b: the desired value
 * @n: number of bytes to be changed
 *
 * Return: pointer to the destination memory block
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned char *ptr = (unsigned char *)s;
    unsigned char value = (unsigned char)b;

    for (unsigned int i = 0; i < n; i++)
    {
        ptr[i] = value;
    }

    return s;
}
