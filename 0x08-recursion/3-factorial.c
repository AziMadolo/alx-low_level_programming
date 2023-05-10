#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: The number to calculate the factorial of.
 *
 * Return: The factorial of the number.
 */
int factorial(int n)
{
	if (n < 0)
	{
		return -1; /* Return -1 to indicate an error */
	}
	else if (n == 0)
	{
		return 1; /* Factorial of 0 is 1 */
	}
	else
	{
		return n * factorial(n - 1);
	}
}
