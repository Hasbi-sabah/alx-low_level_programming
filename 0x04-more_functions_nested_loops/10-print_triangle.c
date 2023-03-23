#include "main.h"

/**
 * print_triangle - draws a triangle on the terminal
 *@size: size of the triangle
 *
 * Return: none
 */

void print_triangle(int size)
{
	int i, j;

	if (size > 0)
	{
		for (j = 1; j <= size; j++)
		{
			for (i = j; i < size; i++)
				_putchar(' ');
			for (i = 1; i <= j; i++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
