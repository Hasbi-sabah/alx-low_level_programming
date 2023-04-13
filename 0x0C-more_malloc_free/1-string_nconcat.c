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
	unsigned int i, j, len1, len2;
	char *p;

	for (len1 = 0; s1 != NULL && s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2 != NULL && s2[len2] != '\0'; len2++)
		;
	if (n > len2)
		n = len2;
	p = malloc(sizeof(char) * (len1 + n + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; s1 != NULL && i < len1; i++)
		p[i] = s1[i];
	for (j = 0; s2 != NULL && j < n; j++)
		p[i + j] = s2[j];
	p[len1 + n] = '\0';
	return (p);
	free(p);
}
