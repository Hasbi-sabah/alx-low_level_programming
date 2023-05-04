#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal;
	int len, mult;

	if (!b)
		return (0);
	len = _strlen(b) - 1;
	for (decimal = 0, mult = 1; len >= 0; len--, mult *= 2)
	{
		if (_atoi(b[len]) == -1)
			return (0);
		decimal += _atoi(b[len]) * mult;
	}
	return (decimal);
}

/**
 * _strlen - swaps the values of two integers.
 * @s: string
 * Return: length if string
 */

int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _atoi - convert a string to an integer
 * @s: string
 * Return: integer
 */

int _atoi(const char s)
{
	if (s != '0' && s != '1')
		return (-1);
	return (s - '0');
}
