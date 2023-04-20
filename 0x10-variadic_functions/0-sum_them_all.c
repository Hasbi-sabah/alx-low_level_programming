#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: number of parameters
 * Return: sum or 0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list pars;

	if (n == 0)
		return (0);
	va_start(pars, n);
	for (i = 0, sum = 0; i < n; i++)
	{
		sum += va_arg(pars, int);
	}
	va_end(pars);
	return (sum);
}
