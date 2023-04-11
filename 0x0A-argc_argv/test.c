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
	int i, sum;

	for (i = 1, sum = 0; i < argc; i++)
	{
		if (atoi(argv[i]) == 0 && *argv[i] != '0')
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}
	printf("%i\n", sum);
	return (0);
}
