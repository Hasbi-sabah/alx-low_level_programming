#include "lists.h"

/**
 * free_listint_free - frees a listint_t list.
 * @head: head of list
 */

size_t free_listint_safe(listint_t **h)
{
	int i;
	listint_t *temp;

	if (!*h)
		return (0);
	for (i = 0; *h; *h = (*h)->next, free(temp), i++)
	{
		if (*h >= (*h)->next)
		{
			*h = (*h)->next
			temp = *h;
			free(temp);
			i++;
		}
		temp = *h;
	}
	*h = NULL;
	return (i);
}
