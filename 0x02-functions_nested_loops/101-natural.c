#include <stdio.h>

/**
 * add - adds two integers and returns the result
 *@n1: first number
 *@n2: second number*
 * Return: result of addition
 */
int main(void)
{
	int n, sum;

	for (n = 0; n < 1024; n++)
	{
		if ((n % 3) == 0 || (n % 5) == 0)
			sum += n;
	}
	printf("%i\n", sum);
	return (0);
}
