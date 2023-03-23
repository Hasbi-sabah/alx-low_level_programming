#include "main.h"

/**
 *main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	unsigned long n = 123195, i, j, num1 = 0, num2 = 0;

	for (i = n - 1; i > 2; i--) 
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				num2 = 0;
				break;
			}
			else
				num2 = i;
		}
		if (num2 != 0 && n % num2 == 0)
		{
			num1 = num2;
			break;
		}
	}

	printf("%lu\n", num1);
	return (0);
}
