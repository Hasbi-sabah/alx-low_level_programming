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
		if (str[i] == ' ' && (i != 0 || str[i - 1] != ' '))
			words++;
	}
	if (str[i - 1] == ' ')
		words++;
	p = malloc(sizeof(char *) * (words + 1));
	if (p == NULL || words == 0)
		return (NULL);
	for (i = 0, k = 0; k <= words && str[i] != '\0'; i++, k++)
	{
		if (str[i] != ' ')
		{
			for (len = 0; str[i + len] != ' ' && str[i + len] != '\0'; len++)
				;
			p[k] = malloc(sizeof(char) * (len + 2));
			if (p[k] == NULL)
			{
				for (; k >= 0; k--)
					free(p[k]);
				free(p);
				return (NULL);
			}
			for (j = 0; j < len; j++, i++)
				p[k][j] = str[i];
			p[k][j] = '\0';
			if (str[i] != '\0')
				i--;
		}
		else if (str[i] == ' ' && str[i + 1] == '\0')
			break;
		else
			k--;
	}
	return (p);
}
