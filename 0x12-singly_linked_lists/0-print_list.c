#include "lists.h"

size_t print_list(const list_t *h)
{
	for (; h; h = h->next)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
		{
			printf("[%u] ", h->len);
			printf("%s\n", h->str);
		}
	}
	return (1);
}
