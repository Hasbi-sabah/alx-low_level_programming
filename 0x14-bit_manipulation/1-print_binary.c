#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: decimal number
 */

void print_binary(unsigned long int n)
{
	unsigned long int flip;
	int i;

	if (n == 0)
		_putchar('0');
	for (flip = 0, i = 0; n > 0; i++, n >>= 1)
	{
		flip <<= 1;
		flip |= (1 & n);
	}
	for (; i; flip >>= 1, i--)
		_putchar((1 & flip) + '0');
}
