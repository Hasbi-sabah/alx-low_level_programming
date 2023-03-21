#include <stdio.h>

/**
 * main - entrey point
 *
 * Return: always 0
 */
int main(void)
{
	unsigned long a, a2, a3, sum1;
	unsigned long b, b2, b3, sum2;
	int i;

	printf("1, 2");
	for (a = 1, b = 2, i = 1; i < 90; i++)
	{
		sum1 = a + b;
		printf(", %ld", sum1);
		a = b;
		b = sum1;
	}
	a2 = a % 1000;
	a3 = a / 1000;
	b2 = b % 1000;
	b3 = b / 1000;
	for (; i < 97; i++)
	{
		sum2 = (a2 + b2) / 1000;
		a = (a2 + b2) - sum2 * 1000;
		b = (a3 + b3) + sum2;
		a2 = b2;
		b2 = a;
		a3 = b3;
		b3 = b;
		if (a >= 100)
			printf("%lu%lu", a, b);
		else
			printf("%lu0%lu", a, b);
		if (i != 96)
			printf(", ");
	}
	printf("\n");
	return (0);
}
