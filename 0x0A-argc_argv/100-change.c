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
	int n, coin;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("0\n");
		return (0);
	}
	for (coin = 0; n > 0; coin++)
	{
		if (n >= 25)
			n -= 25;
		else if (n >= 10)
			n -= 10;
		else if (n >= 5)
			n -= 5;
		else if (n >= 2)
			n -= 2;
		else
			n -= 1;
	}
	printf("%i\n", coin);
	return (0);
}
