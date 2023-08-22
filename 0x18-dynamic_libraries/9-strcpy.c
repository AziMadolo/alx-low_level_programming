#include "main.h"

/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Pointer to the destination character array.
 * @src: Pointer to the source character array.
 * Description: This function duplicates the string content pointed to by `src`
 *              and stores it in the buffer pointed to by `dest`.
 * Return: Pointer to the beginning of `dest`.
 */

char *_strcpy(char *dest, char *src)
{
    int index = -1;

    // Copy each character from the source string to the destination string
    do {
        index++;
        dest[index] = src[index];
    } while (src[index] != '\0'); // Continue until the end of the source string is reached

    return (dest); // Return the pointer to the beginning of the destination string
}
