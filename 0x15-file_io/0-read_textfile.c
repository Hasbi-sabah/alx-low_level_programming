#include "main.h"

/**
 * read_textfile - reads a text file and prints it to stdout.
 * @filename: filename/ path
 * @letters: number of letters to be printed
 * Return: actual number of letters printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t n;
	int ret;
	char *hold;

	if (!filename)
		return (0);
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		return (0);
	hold = malloc(letters);
	if (!hold)
		return (0);
	n = read(ret, hold, letters);
	if (n == -1)
		return (0);
	n = write(STDOUT_FILENO, hold, n);
	if (n == -1)
		return (0);
	close(ret);
	return (n);
}
