#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int f1(int n)
{
	return ((n ^ 0x3b) & 0x3f);
}
int f2(long n1, int n2)
{
	int i, j;

	for (i = 0, j = 0; i < n2; i++)
		j += (int)*(char *)(n1 + i);
	return ((j ^ 0x4f) & 0x3f);
}
int f3(long n1, int n2)
{
	int i, j;

	for (i = 0, j = 1; i < n2; i++)
		j = (int)*(char *)(n1 + i) * j;
	return ((j ^ 0x55) & 0x3f);
}
int f4(char *n1, int n2)
{
	int var, i, j;

	for (i = 0, j = (int)*n1; i < n2; i++)
	{
		if (j < (int)n1[i])
			j =(int)n1[i];
	}
	srand(j ^ 0xe);
	var = rand();
	return (var & 0x3f);
}
int f5(long n1, int n2)
{
	int bvar;
	int i;

	for (i = 0, bvar = 0; i < n2; i++)
		bvar = bvar + *(char *)(n1 + i) * *(char *)(n1 + i);
	return ((bvar ^ 0xef) & 0x3f);
}
int f6(char n1)
{
	int i, j;

	for (i = 0, j = 0; i < n1; i++)
		j = rand();
	return ((j ^ 0xe5) & 0x3f);
}
int main(int argc, char *argv[])
{
	char *s1;
	char *args = malloc(sizeof(char) * 6);
	int var;
	long local[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };

	(void) argc;
	s1 = argv[1];
	var = f1(strlen(s1) & 0xffffffff);
	args[0] = ((char *)local)[var];
	var = f2((long)s1, strlen(s1));
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
	return 0;
}
