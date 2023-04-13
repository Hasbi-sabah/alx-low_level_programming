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

	if (s2 == NULL || s2[0] == '\0')
		n = 0;
	p = malloc(sizeof(s1) + n);
	if (p == NULL)
		return (NULL);
	for (i = 0; s1 != NULL && s1[i] != '\0'; i++)
		p[i] = s1[i];
	for (j = 0; s2 != NULL && j < n; j++)
		p[i + j] = s2[j];
	return (p);
	free(p);
}
