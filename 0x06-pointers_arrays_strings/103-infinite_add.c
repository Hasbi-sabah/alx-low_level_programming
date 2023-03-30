#include "main.h"
#include <stdio.h>

/**
 * infinite_add - adds two numbers.
 *
 *@n1: number 1
 *@n2: number 2
 *@r: buffer that the function will use to store the result
 *@size_r: buffer size
 *
 * Return: string, or 0 if impossible
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, k;
	int biggest, sum, leftover;

	for (l1 = 0; n1[l1] != '\0'; l1++)
		;
	for (l2 = 0; n2[l2] != '\0'; l2++)
		;
	l1--, l2--, size_r--;
	if (l1 >= l2)
		biggest = l1;
	else
		biggest = l2;
	if (biggest + 2 <= size_r)
	{
		for (k = 0, leftover = 0; biggest >= 0; k++, l1--, l2--, biggest--)
		{
			sum = 0;
			if (l1 >= 0 && l2 >= 0)
				sum = (n1[l1] - '0') + (n2[l2] - '0') + leftover;
			else if (l1 >= 0)
				sum = (n1[l1] - '0') + leftover;
			else
				sum = (n2[l2] - '0') + leftover;
			if (sum >= 10)
			{
				sum = sum - 10;
				leftover = 1;
			}
			else
				leftover = 0;
			*(r + biggest + 1) = sum + '0';
		}
		if (leftover == 1)
			*(r + 0) = leftover + '0';
		for (k += 1; k <= size_r; k++)
			*(r + k) = '\0';
		return (r);
	}
	else
		return (0);
}
