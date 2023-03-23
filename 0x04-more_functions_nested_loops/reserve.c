#include "main.h"
#include <stdio.h>

/**
 * print_number - prints an integer
 *@n: integer to be printed
 *
 * Return: none
 */

void print_number(int n)
{
	int m, i, j, k;
	if (n != 0)
	{
		if (n < 0)
		{
			n = -n;
			_putchar('-');
		}
		for (i = 1, m = n; m >= 10; i++)
			m /= 10;
		_putchar('0' + m);
		for (j = 2; j < i && n >= 100 ; j++)
		{
			m = n;
			for (k = i - j; k > 0; k--)
				m = m / 10;
			_putchar('0' + (m % 10));
		}
		if (n >= 10)
			_putchar('0' + (n % 10));
	}
	else
		_putchar('0');
}
