#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes from s2
 *
 * Return: Pointer or NULL
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	char *p;

	p = malloc(sizeof(s1) + n + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; s1[i] != 0 && s1 != NULL; i++)
		p[i] = s1[i];
	for (j = 0; s2[j] != 0 && s2 != NULL && j <= n; j++)
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
