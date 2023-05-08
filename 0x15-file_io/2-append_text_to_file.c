#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: filename
 * @text_content: text content
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ret;
	ssize_t n;

	if (!filename)
		return (-1);
	if (!text_content)
		return (1);
	ret = open(filename, O_RDWR | O_APPEND);
	if (ret == -1)
		return (-1);
	n = write(ret, text_content, strlen(text_content));
	if (n == -1)
		return (-1);
	return (1);
}
