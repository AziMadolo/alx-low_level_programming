#include "main.h"

/**
 * _strncpy - Copies a string up to a specified number of bytes.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * @n: Number of bytes to copy from source.
 * Return: Pointer to the destination buffer.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int index;

    // Copy characters from source to destination until n bytes or null terminator is reached
    for (index = 0; index < n && src[index] != '\0'; index++)
    {
        dest[index] = src[index];
    }

    // Fill remaining bytes in destination with null terminators
    while (index < n)
    {
        dest[index] = '\0';
        index++;
    }

    return (dest);
}
