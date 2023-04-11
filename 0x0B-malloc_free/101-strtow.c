#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * strtow - splits a string into words.
 *
 * @str: string
 *
 * Return: pointer to array of strings
 */

char **strtow(char *str)
{
	char **p;
	int i, j, k, words, len;

	for (i = 0, words = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && i != 0 && str[i - 1] != ' ')
			words++;
	}
	p = malloc(sizeof(char *) * (words + 1));
	if (p == NULL || words == 0)
		return (NULL);
	for (i = 0, k = 0; k < words; i++, k++)
	{
		if (str[i] != ' ')
		{
			for (len = 0; str[len] != ' ' && str[len] != '\0'; len++)
				;
			p[k] = malloc(sizeof(char) * (len + 2));
			if (p[k] == NULL)
			{
				for (; k >= 0; k--)
					free(p[k]);
				free(p);
				return (NULL);
			}
			for (j = 0; str[i] != ' '; j++, i++)
				p[k][j] = str[i];
			p[k][j + 1] = '\0';
		}
		else
			k--;
	}
	return (p);
}
