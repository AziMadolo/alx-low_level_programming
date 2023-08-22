#include "main.h"
/**
 * calculate_length - Computes the length of a string
 * @s: Pointer to the string to be measured
 * Return: Length of the string
*/

int calculate_length(char *s)
{
    int count = 0;
    while (s[count])
        count++;

    return (count);
}
