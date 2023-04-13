#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes of ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer or NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *x_ptr;
	unsigned int i;

	x_ptr = (char *)ptr;
	if (new_size == 0 && x_ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	for (i = 0; x_ptr != NULL
			&& i < old_size && i < new_size; i++)
		p[i] = x_ptr[i];
	free(ptr);
	return (p);
}
