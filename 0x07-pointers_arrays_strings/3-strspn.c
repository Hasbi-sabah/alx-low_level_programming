#include <stdio.h>

/**
 * _strspn - gets the length of a prefix substring.
 *
 * @s: string
 * @accept: characters to accept
 *
 * Return: number or 0
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n;
	int i, j;

	for (i = 0, n = 0; accept[i] != '\0'; i++)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			if (accept[i] == s[j])
				break;
		}
		if (s[j] != '\0')
			n++;
	}
	return (n);
}
