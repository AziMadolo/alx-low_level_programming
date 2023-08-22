#include "main.h"
#include <stdio.h>
/**
 * _isupper - verify whether c is uppercase
 *
 * @c: character input to check
 *
 * Return: 1 if it's uppercase, 0 if not
*/

int _isupper(int c)
{
    if (c >= 65 && c <= 90)
        return (1);
    else
        return (0);
}
