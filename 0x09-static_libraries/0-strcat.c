#include "main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string
 */

char *_strcat(char *dest, const char *src)
{
    char *result = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return result;
}
