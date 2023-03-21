#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - prints characters
 *
 * Return: void
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);
	putchar('\n');
}
