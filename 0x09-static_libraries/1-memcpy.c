#include "main.h"
/**
 * _memcpy - a function that copies memory area
 * @dest: memory where is stored
 * @src: memory where is copied
 * @n: number of bytes
 *
 * Return: copied memory with n bytes changed
 */
char *_memcpy(char *dest, const char *src, unsigned int n)
{
    char *result = dest;

    while (n--)
    {
        *dest++ = *src++;
    }

    return result;
}
