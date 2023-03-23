#include "main.h"
#include <math.h>

/**
 *main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	long n = 612852475143;
	int c;

	for (c = sqrt (n); c > 2; c++) 
	{
		if (n % c == 0)
			break;
	}

	printf("%i\n", c);
	return (0);
}
