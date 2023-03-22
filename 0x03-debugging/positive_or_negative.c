#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
  * positive_or_negative - Entry point
  *
  * Return: Always 0 (Success)
  */

void positive_or_negative(int n)
{
	if (n > 0)
		printf("%i is positive\n", n);
	else if (n < 0)
		printf("%i is negative\n", n);
	else
		printf("%i is zero\n", n);
}
