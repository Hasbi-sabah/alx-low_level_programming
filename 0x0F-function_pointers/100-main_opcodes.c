#include <stdio.h>
#include <stdlib.h>

/**
 * main -entry way
 * @ac: arg number
 * @av: args
 * Return: 0
 */

int main(int ac, char *av[])
{
	int i, j;
	char *address;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (atoi(av[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	address = (char *)main;
	for (i = 0; i < atoi(av[1]); i++)
	{
		if (i == (atoi(av[1]) - 1))
		{
			printf("%.2hhx\n", address[i]);
			return (0);
		}
		printf("%02hhx ", address[i]);
	}
	return (0);
}
