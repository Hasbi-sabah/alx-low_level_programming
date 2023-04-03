#include <stdio.h>

/**
 * _strstr - locates a substring.
 *
 * @haystack: string
 * @needle: string looking for
 *
 * Return: location or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, n;

	if (*haystack == '\0' && *needle == '\0')
		return (0);
	for (i = 0, n = 0; needle[i] != '\0'; i++)
	{
		for (j = 0; haystack[j] != '\0'; j++)
		{
			if ((haystack[j] == needle[i]
					&& n == 0)
					|| (haystack[j - 1] == needle[i - 1]
						&& haystack[j] == needle[i]))
				break;
		}
		if (haystack[j] != '\0' && n == 0)
			n = j;
		else if (haystack[j] == '\0')
			n = 0;
	}
	if (n != 0)
		return (&haystack[n]);
	else
		return (0);
}
