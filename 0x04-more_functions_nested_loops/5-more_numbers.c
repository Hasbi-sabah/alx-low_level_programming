#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 * followed by a new line
 *
 * Return: none
 */

void more_numbers(void)
{
	int x, y;

	for (y = 0; y < 10; y++)
	{
		for (x = 0; x <= 14; x++)
		{
			if (x >= 10)
				_putchar('0' + (x / 10));
			_putchar('0' + (x % 10));
		}
	_putchar('\n');
	}
}
