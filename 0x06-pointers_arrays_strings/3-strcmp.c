#include "main.h"

/**
 * _strcmp - compares two strings
 *
 *@s1: first string
 *@s2: second string
 *
 *Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int sum1, sum2, i;

	for (sum1 = 0, i = 0; s1[i] != '\0'; i++)
		sum1 = (sum1 * 10) + s1[i] - '0';
	for (sum2 = 0, i = 0; s2[i] != '\0'; i++)
		sum2 = (sum2 * 10) + s2[i] - '0';
	return (sum1 - sum2);
}
