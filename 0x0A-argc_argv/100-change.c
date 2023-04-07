#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * @argc: int
 * @argv: vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, arg, sum;
	char *p;

	for (i = 1, sum = 0; i < argc; i++)
	{
		arg = strtol(argv[i], &p, 10);
		if (*p !=  '\0')
		{
			printf("Error\n");
			return (1);
		}
		sum += arg;
	}
	printf("%i\n", sum);
	return (0);
}
