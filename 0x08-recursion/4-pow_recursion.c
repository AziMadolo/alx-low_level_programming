#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: The base.
 * @y: The exponent.
 *
 * Return: The value of x raised to the power of y.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return -1; /* Return -1 to indicate an error */
	}
	else if (y == 0)
	{
		return 1; /* Anything raised to the power of 0 is 1 */
	}
	else
	{
		return x * _pow_recursion(x, y - 1);
	}
}	

