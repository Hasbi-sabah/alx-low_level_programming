#include <stdio.h>
#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59
 *
 * Return: none
 */
void jack_bauer(void)
{
	int s, m;
	for (s = 0; m < 60; m++)
	{
		for (s=1; s <= 60; s++)
		{
			_putchar('0' + m);
			_putchar(':');
			_putchar('0' + s);
			_putchar('\n');
		}	
	}
}
