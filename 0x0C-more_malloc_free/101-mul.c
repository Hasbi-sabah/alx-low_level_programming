#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void _print_error(char *str);
int _is_digit(char *av, int len);
/**
 * main - entry point
 *
 * @ac: array size
 * @av: array
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	int i, j, len1, len2, sum, leftover;
	int *p_total, c1, c2;

	if (ac != 3)
	{
		_print_error("Error\n");
		exit(98);
	}
	for (len1 = 0; av[1][len1] != '\0'; len1++)
		;
	for (len2 = 0; av[2][len2] != '\0'; len2++)
		;
	if (!_is_digit(av[1], len1) || !_is_digit(av[2], len2))
	{
		_print_error("Error\n");
		exit(98);
	}
	p_total = malloc(sizeof(int) * (len1 + len2 + 1));
	if (p_total == NULL)
	{
		_print_error("Error\n");
		exit(98);
	}
	for (i = 0; i <= len1 + len2; i++)
		p_total[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		c1 = av[1][i] - '0';
		for (j = len2 - 1, sum = 0, leftover = 0; j >= 0; j--)
		{
			c2 = av[2][j] - '0';
			sum += p_total[i + j + 1] + (c1 * c2) + leftover;
			p_total[i + j + 1] = sum % 10;
			leftover = sum / 10;
		}
		if (leftover > 0)
			p_total[i + j + 1] += leftover;
	}
	for (i = 0; i < len1 + len2; i++)
	{
		if (p_total[i] == 0)
		{
			_putchar('0');
			break;
		}
			_putchar(p_total[i] + '0');
	}
	_putchar('\n');
	free(p_total);
	return (0);
}

/**
 * _print_error - prints the word Error
 * @str: string to be printed
 */

void _print_error(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
/**
 * _is_digit - checks if string is all digits
 * @av: string to be checked
 * @len: string length
 * Return: 0 or 1
 */

int _is_digit(char *av, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
	}
	return (1);
}
