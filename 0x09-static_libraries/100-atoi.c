#include "main.h"

/**
 * _atoi - Converts a string into an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sig = 1;
    unsigned int unsig = 0;
    int i = 0;

    while (*s)
    {
        if (*s == '-')
            sig *= -1;
        else if (*s >= '0' && *s <= '9')
        {
            unsig = (unsig * 10) + (*s - '0');
        }
        else if (unsig > 0)
        {
            break;
        }
        s++;
    }

    return (unsig * sig);
}
