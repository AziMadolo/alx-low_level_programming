#include "main.h"

/**
 * sqrt_helper - Helper function for calculating the square root recursively.
 * @n: The number whose square root is being calculated.
 * @i: The current guess for the square root.
 *
 * Return: The square root of n if it exists, -1 otherwise.
 */
int sqrt_helper(int n, int i)
{
	if (i * i > n)
	{
		return -1; /* Return -1 if n does not have a natural square root */
	}
	else if (i * i == n)
	{
		return i; /* Return the square root of n */
	}
	else
	{
		return sqrt_helper(n, i + 1); /* Try the next guess */
	}
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number whose square root is being calculated.
 *
 * Return: The square root of n if it exists, -1 otherwise.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return -1; /* Return -1 to indicate an error */
	}
	else
	{
		return sqrt_helper(n, 0); /* Start with a guess of 0 */
	}
}
