#include "main.h"

/**
 * _strpbrk - Find the first occurrence of any character from accept in s
 * @s: The string to search
 * @accept: The characters to search for
 *
 * Return: Pointer to the first occurrence of a matching character in s,
 *         or NULL if no match is found
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        char *ch = accept;
        while (*ch != '\0')
        {
            if (*ch == *s)
                return s;
            ch++;
        }
        s++;
    }
    
    return NULL;
}
