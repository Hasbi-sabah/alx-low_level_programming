#include "main.h"

/**
 * rev_string - reverses a string
 *
 *@s: string
 */

void rev_string(char *s)
{
	int i, j;
	char rev_str;

	for (i = 0; s[i] != '\0'; i++)
		;
	for (j = 0; j <= i / 2; j++)
	{
		rev_str = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = rev_str;
	}
}
