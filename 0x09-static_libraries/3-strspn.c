#include "main.h"
/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int n = 0;
    
    while (*s)
    {
        char *ptr = accept;
        while (*ptr)
        {
            if (*s == *ptr)
            {
                n++;
                break;
            }
            ptr++;
        }
        if (*ptr == '\0')
            return n;
        s++;
    }
    return n;
}
