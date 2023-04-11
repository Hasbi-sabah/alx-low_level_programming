#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer or NULL
 */

char *str_concat(char *s1, char *s2)
{
	char *p;
	int i = 0, len1 = 0, len2 = 0;

	for (len1 = 0; s1 != NULL && s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2 != NULL && s2[len2] != '\0'; len2++)
		;
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < len1 && s1 != NULL; i++)
		p[i] = s1[i];
	for (i = 0; i < len1 + len2 && s2 != NULL; i++)
		p[len1 + i] = s2[i];
	return (p);
	free(p);
}
