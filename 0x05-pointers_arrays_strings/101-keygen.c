#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	printf("%d\n", rand() % INT_MAX);
	return (0);
}
