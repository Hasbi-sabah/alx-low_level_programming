#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */

char *_strcat(char *dest, char *src)
{
	int i, j, k;
	for (j = 0; dest[j] != '\0'; j++)
		;
	dest[j] = ' ';
	for (i = j, k = 0; src[k] != '\0'; i ++, k++)
		dest[i] = src[k];
	dest[i] = '\0';
	return (dest);
}
