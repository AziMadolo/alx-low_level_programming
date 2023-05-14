#include "main.h"

/**
 * _strncat - concatenate two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to concatenate from src
 *
 * Return: pointer to the resulting string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    char *dest_end = dest;

    // Find the end of the destination string
    while (*dest_end != '\0')
        dest_end++;

    // Copy at most n bytes from src to the destination string
    while (*src != '\0' && n > 0)
    {
        *dest_end = *src;
        dest_end++;
        src++;
        n--;
    }

    *dest_end = '\0'; // Add the null-terminating character

    return dest;
}
