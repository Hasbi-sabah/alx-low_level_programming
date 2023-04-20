#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list pars;
	unsigned int i;
	const char *p = separator, *arg;

	va_start(pars, n);
	for (i = 0; i < n; i++)
	{
		arg = va_arg(pars, char *);
		if (arg)
			printf("%s", arg);
		else
			printf("(nil)");
		if (separator && i != n - 1)
			printf("%s", p);
	}
	printf("\n");
}
