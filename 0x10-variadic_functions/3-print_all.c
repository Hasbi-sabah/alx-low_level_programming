#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list pars;
	char_list printer[] = {
		{'c', c_print},
		{'i', i_print},
		{'f', f_print},
		{'s', s_print}
	};
	int i, j;

	i = 0;
	va_start(pars, format);
	while (format && format[i])
	{
		j = 0;
		while (printer[j].chars)
		{
			if (format[i] == printer[j].chars)
			{
				printer[j].f(pars);
				if (format[i + 1])
					printf(", ");
				break;
			}
			j++;
		}
		i++;
	}
	va_end(pars);
	printf("\n");
}

/**
 * c_print - prints c
 * @pars: va list
 */

void c_print(va_list pars)
{
	printf("%c", va_arg(pars, int));
}

/**
 * i_print - prints i
 * @pars: va list
 */

void i_print(va_list pars)
{
	printf("%i", va_arg(pars, int));
}

/**
 * f_print - prints f
 * @pars: va list
 */

void f_print(va_list pars)
{
	printf("%f", va_arg(pars, double));
}

/**
 * s_print - prints s
 * @pars: va list
 */

void s_print(va_list pars)
{
	char *p;

	p = va_arg(pars, char *);
	switch (!!p)
	{
		case 0:
			p = "(nil)";
			break;
	}
	printf("%s", p);
}
