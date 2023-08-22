#include "main.h"

/**
 * _isdigit - Determines if the input represents a digit between 0 and 9.
 * @c: Input character to be checked.
 * Return: 1 if the character is a digit (0 to 9), 0 otherwise.
 */
int _isdigit(int c)
{
    if (c >= 48 && c <= 57)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
