#include "main.h"

/**
 * char *_strcpy - Copies the string pointed to by src
 *
 * @dest: Copy to
 * @src: Copy from
 *
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
    char *dest_ptr = dest;

    while ((*dest++ = *src++))
        ;

    return dest_ptr;
}
