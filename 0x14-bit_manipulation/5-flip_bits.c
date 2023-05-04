#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * @n: number 1
 * @m: number 2
 * Return: number of bytes
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	int i;

	for (i = 0, diff = n ^ m; diff; diff >>= 1)
	{
		if (diff & 1)
			i++;
	}
	return (i);
}
