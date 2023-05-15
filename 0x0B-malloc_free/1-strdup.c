#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
    if (str == NULL)
        return NULL;

    int length = 0;
    while (str[length] != '\0')
        length++;

    char *aaa = malloc(sizeof(char) * (length + 1));
    if (aaa == NULL)
        return NULL;

    for (int i = 0; str[i] != '\0'; i++)
        aaa[i] = str[i];

    return aaa;
}
