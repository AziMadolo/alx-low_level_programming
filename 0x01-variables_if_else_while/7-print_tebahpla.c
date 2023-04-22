#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * Entry point
 * Return: Always 0
 */

int main(void)

{
	char low;

	for (low = 'z'; low >= 'a'; low--)
	putchar(low);
	putchar('\n');

	return (0);

}
