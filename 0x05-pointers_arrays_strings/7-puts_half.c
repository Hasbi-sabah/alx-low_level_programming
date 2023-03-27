#include "main.h"

/**
 * puts_half -  half of a string, followed by a new line.
 *
 *@str: string
 */

void puts_half(char *str)
{
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
		;
	if (i % 2 != 0)
		i -= 1;
	for (j = i / 2; j <= i - 1; j++)
		_putchar(str[j]);
	_putchar('\n');
}
