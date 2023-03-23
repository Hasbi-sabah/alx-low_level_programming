#include "main.h"

/**
 * print_number - blabla
 *@num: number
 */

void print_number(int num)
{
	unsigned int length = 0;
	int isNegative = 0;
	int j;
	int i;

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	j = num;
	while (j / 10)
	{
		i = j / 10;
		length++;
	}
	if (isNegative)
		_putchar('-');
	for (j = length; j > 0; j--)
	{
		int expo = 1;

		for (i = 0; i < j; ++i)
			expo *= 10;
		_putchar((num / expo) % 10 + '0');
	}
	_putchar(num % 10 + '0');
}
