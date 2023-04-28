#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: position
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	int i;

	for (i = 0; h; h = h->next, i++)
		;
	return (i);
}
