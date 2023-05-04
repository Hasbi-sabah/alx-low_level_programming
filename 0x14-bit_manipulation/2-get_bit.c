#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: number
 * @index: index
 * Return: the value of the bit at index index or -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (unsigned long int)get_length(n))
		return (-1);
	n >>= index;
	return (n & 1);
}

/**
 * get_length - gets length of binary int
 * @n: binary int
 * Return: int
 */

int get_length(unsigned long int n)
{
	int i;

	for (i = 0; n > 0; i++)
		n >>= 1;
	return (i);
}
