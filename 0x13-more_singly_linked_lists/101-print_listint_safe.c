#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	int i;

	for (i = 0; head; head = head->next, i++)
	{
		printf("[%p] %i\n", (void *)&head, head->n);
	}
	return (i);
}
