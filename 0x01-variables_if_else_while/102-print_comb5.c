#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: Always 0 (Success)
  */

int main(void)
{
	int n1, n2, n3, n4;

	for (n1 = 0, n2 = 0, n3 = 0, n4 = 0; n1 <= 9; n1++)
	{
		for (n2 = 0; n2 <= 9; n2++)
		{
			for (n3 = n1; n3 <= 9; n3++)
			{
				if (n3 == 0 && n4 == 0)
					n4 = n2 + 1;
				else
					n4 = 0;
				for (; n4 <= 9; n4++)
				{
					if (!(n1 == 9 && n2 == 9))
					{
						putchar('0' + n1);
						putchar('0' + n2);
						putchar(' ');
						putchar('0' + n3);
						putchar('0' + n4);
						if (!(n1 == 9 && n3 == 9 && n4 == 9 && n2 == 8))
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
