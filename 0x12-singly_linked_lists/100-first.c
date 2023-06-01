#include <stdio.h>

void first(void) __attribute__((constructor));

/**
 * first - prints a sentence before the main
 * function is executed
 */
void first(void)
{
	char *sentence1 = "You're beat! and yet, you must allow,\n";
	char *sentence2 = "I bore my house upon my back!\n";
	
	printf("%s%s", sentence1, sentence2);
}
