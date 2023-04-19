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
	int i;
	char *address;

	if (ac != 2)
	{
		printf("Error");
		exit(1);
	}
	if (atoi(av[1]) < 0)
	{
		printf("Error");
		exit(2);
	}
	address = (char *)main;
	for (i = 0; i < atoi(av[1]); i++)
	{
		printf("%02hhx ", address[i]);
		if (i == atoi(av[1]) - 1)
			printf("%2hhx\n", address[i]);

	}
	return (0);
}
