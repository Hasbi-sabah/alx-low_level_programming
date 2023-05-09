#include "main.h"

/**
 * main - copies the content of a file to another file.
 * @ac: number of arguments
 * @av: arguments
 * Return: always 0
 */

int main(int ac, char **av)
{
	int ret_from, ret_to;
	ssize_t n_from, n_to;
	char *from = NULL, *to = NULL, buffer[1024];

	if (ac != 3)
		error(97, from, to);
	from = av[1];
	to = av[2];
	ret_from = open(from, O_RDONLY);
	if (ret_from == -1)
		error(98, from, to);
	ret_to = open(to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (ret_to == -1)
		error(99, from, to);
	do {
		n_from = read(ret_from, buffer, 1024);
		if (n_from == -1)
			error(98, from, to);
		n_to = write(ret_to, buffer, n_from);
		if (n_to == -1)
			error(99, from, to);
	} while (n_from > 0);
	n_from = close(ret_from);
	n_to = close(ret_to);
	if (n_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", ret_from);
		exit(100);
	}
	if (n_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", ret_to);
		exit(100);
	}
	return (0);
}

/**
 * error - prints error messages then exit
 * @n: exit value
 * @from: holds the filename from
 * @to: holds the filename to
 */

void error(int n, char *from, char *to)
{
	switch (n)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
			break;
	}
	exit(n);
}
