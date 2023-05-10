#include "main.h"

/**
 * _strlen - Computes the length of a string recursively.
 * @s: The string to compute the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	if (*s == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + _strlen(s + 1);
	}
}

/**
 * is_pal_helper - Helper function to check if a string is a palindrome recursively.
 * @s: The string to be checked.
 * @start: The index of the first character in the string.
 * @end: The index of the last character in the string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_pal_helper(char *s, int start, int end)
{
	if (start >= end)
	{
		return 1; /* Return 1 if the string is a palindrome */
	}
	else if (s[start] != s[end])
	{
		return 0; /* Return 0 if the string is not a palindrome */
	}
	else
	{
		return is_pal_helper(s, start + 1, end - 1); /* Check the next pair of characters */
	}
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to be checked.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = _strlen(s); /* Compute the length of the string */
	int start = 0;
	int end = len - 1;

	return is_pal_helper(s, start, end); /* Check if the string is a palindrome */
}
