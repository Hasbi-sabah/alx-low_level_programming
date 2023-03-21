#include <stdio.h>
#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 *@n: number to be checked
 *
 * Return: last digit of a number
 */
int print_last_digit(int n)
{
	if (n < 0)
		n = n * (-1);
	n = n % 10;
	_putchar('0' + n);
	return (n);
}
