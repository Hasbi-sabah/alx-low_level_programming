#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 *@n: number of times the character \ should be printed
 *
 * Return: none
 */

void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < j; i++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
