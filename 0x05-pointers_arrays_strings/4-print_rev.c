#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 *
 *@str: string
 */

void print_rev(char *str)
{
	int i;

	for (i = 1; str[i] != '\0'; i++)
		;
	for (; i >= 0; i--)
		_putchar(str[i]);
	_putchar('\n');
}
