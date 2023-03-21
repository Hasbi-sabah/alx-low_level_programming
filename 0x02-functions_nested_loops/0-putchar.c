#include <stdio.h>
#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0 (success)
 */

int main(void)
{
	char c[] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
		_putchar(c[i]);
	putchar('\n');
	return (0);
}
