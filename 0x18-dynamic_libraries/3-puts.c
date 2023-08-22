#include "main.h"

/**
 * _puts - Prints a string followed by a new line
 * @str: Pointer to the string to be printed
 *
 * Description: This function takes a string pointer and prints
 *              each character of the string followed by a new line.
 * Return: void
 */

void _puts(char *str)
{
    int index = 0;

    while (str[index])
    {
        _putchar(str[index]);
        index++;
    }

    _putchar('\n');
}
