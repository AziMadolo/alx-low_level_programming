#include "main.h"

/**
 * is_prime_helper - Helper function to check if a number is prime recursively.
 * @n: The number to be checked.
 * @i: The current divisor being checked.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_helper(int n, int i)
{
	if (n < 2 || n % i == 0)
	{
		return 0; /* Return 0 if n is not prime */
	}
	else if (i > n / 2)
	{
		return 1; /* Return 1 if n is prime */
	}
	else
	{
		return is_prime_helper(n, i + 1); /* Try the next divisor */
	}
}

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return 0; /* Return 0 for negative numbers and 0 or 1 */
	}
	else
	{
		return is_prime_helper(n, 2); /* Start with the divisor 2 */
	}
}
