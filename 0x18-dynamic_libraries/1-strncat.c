#include "main.h"

/**
 * _strncat - Concatenates two strings, with a limit on bytes copied.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Number of bytes to copy from src.
 * 
 * Description:
 * This function appends the characters from src to the end of dest, overwriting
 * the null terminator of dest, and ensuring the concatenated string is null-terminated.
 * The total number of characters copied is limited by n.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_len = 0, src_idx = 0;

    // Calculate the length of the destination string
    while (*(dest + dest_len) != '\0')
    {
        dest_len++;
    }

    // Append characters from src to dest, up to a maximum of n bytes
    while (src_idx < n)
    {
        *(dest + dest_len) = *(src + src_idx);
        
        // If the end of src is reached, terminate the loop
        if (*(src + src_idx) == '\0')
            break;

        // Move to the next character in both src and dest
        dest_len++;
        src_idx++;
    }
    
    return (dest);
}
