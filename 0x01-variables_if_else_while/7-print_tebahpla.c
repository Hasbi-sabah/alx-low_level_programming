#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: Always 0 (Success)
  */

int main(void)
{
	int chr;

	for (chr = 'z'; chr >= 'a'; chr--)
		putchar(chr);
	putchar('\n');
	return (0);
}
