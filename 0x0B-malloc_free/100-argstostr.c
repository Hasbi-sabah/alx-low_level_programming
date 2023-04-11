#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 *
 * @ac: number of arguments
 * @av: argument string
 *
 * Return: string
 */

char *argstostr(int ac, char **av)
{
	char **p;
	int i, j, len;

	if (ac == 0 || av == NULL)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * ac);
	for (i = 0; i < ac ; i++)
	{
		for (len = 0; av[i][len] != '\0'; len++)
			;
		p[i] = (char *)malloc(sizeof(char) * len + 1);
		if (p == NULL)
		{
			for (; i >= 0; i--)
				free(p[i]);
			free(p);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			p[i][j] = av[i][j];
		p[i][len] = '\n';
	}
	return (*p);
}
