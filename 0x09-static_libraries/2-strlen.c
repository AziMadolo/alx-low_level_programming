#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
    int length = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}
