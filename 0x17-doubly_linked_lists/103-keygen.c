#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
 * f3 - f3
 * @n1: n1
 * @n2: len
 * Return: int
 */
int f3(long n1, int n2)
{
	int i, j;

	for (i = 0, j = 1; i < n2; i++)
		j = (int)*(char *)(n1 + i) * j;
	return ((j ^ 0x55) & 0x3f);
}

/**
 * f4 - f4
 * @n1: n1
 * @n2: len
 * Return: int
 */
int f4(char *n1, int n2)
{
	int var, i, j;

	for (i = 0, j = (int)*n1; i < n2; i++)
	{
		if (j < (int)n1[i])
			j = (int)n1[i];
	}
	srand(j ^ 0xe);
	var = rand();
	return (var & 0x3f);
}

/**
 * f5 - f5
 * @n1: n1
 * @n2: len
 * Return: int
 */
int f5(long n1, int n2)
{
	int bvar;
	int i;

	for (i = 0, bvar = 0; i < n2; i++)
		bvar = bvar + *(char *)(n1 + i) * *(char *)(n1 + i);
	return ((bvar ^ 0xef) & 0x3f);
}

/**
 * f6 - f6
 * @n1: n1
 * Return: int
 */
int f6(char n1)
{
	int i, j;

	for (i = 0, j = 0; i < n1; i++)
		j = rand();
	return ((j ^ 0xe5) & 0x3f);
}

/**
 * main - entry point
 * @argc: args
 * @argv: argv
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int i, j;
	char *s1;
	char *args = malloc(sizeof(char) * 6);
	int var;
	long local[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };

	(void) argc;
	s1 = argv[1];
	var = ((strlen(s1) & 0xffffffff) ^ 0x3b) & 0x3f;
	args[0] = ((char *)local)[var];
	for (i = 0, j = 0; i < (int)strlen(s1); i++)
		j += (int)*(char *)((long)s1 + i);
	var = (j ^ 0x4f) & 0x3f;
	args[1] = ((char *)local)[var];
	var = f3((long)s1, strlen(s1));
	args[2] = ((char *)local)[var];
	var = f4(s1, strlen(s1));
	args[3] = ((char *)local)[var];
	var = f5((long)s1, strlen(s1));
	args[4] = ((char *)local)[var];
	var = f6((int)*s1);
	args[5] = ((char *)local)[var];
	printf("%s", args);
	return (0);
}
