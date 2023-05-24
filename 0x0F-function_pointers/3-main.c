#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int num1, num2;
	char *op;
	int result;

	if (argc != 4)
	{
		fprintf(stderr, "Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		fprintf(stderr, "Error\n");
		exit(99);
	}

	if ((*op == '/' && num2 == 0) || (*op == '%' && num2 == 0))
	{
		fprintf(stderr, "Error\n");
		exit(100);
	}

	result = get_op_func(op)(num1, num2);
	printf("%d\n", result);

	return 0;
}

