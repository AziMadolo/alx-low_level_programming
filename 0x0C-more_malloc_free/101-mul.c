#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * print_result - prints the result array
 * @result: array of integers
 * @len: length of the array
 */
void print_result(int *result, int len)
{
	int i, a = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			putchar(result[i] + '0');
	}

	if (!a)
		putchar('0');

	putchar('\n');
}

/**
 * multiply - performs multiplication of two positive numbers
 * @s1: first number as a string
 * @s2: second number as a string
 */
void multiply(char *s1, char *s2)
{
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int len = len1 + len2 + 1;
	int *result = malloc(sizeof(int) * len);
	int i, j, carry, digit1, digit2;

	if (!result)
		errors();

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}

	print_result(result, len);
	free(result);
}

/**
 * main - entry point of the program
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		errors();
		return (1);
	}

	s1 = argv[1];
	s2 = argv[2];

	multiply(s1, s2);

	return (0);
}
