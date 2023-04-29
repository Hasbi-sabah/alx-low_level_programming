#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i;
	const listint_t *temp;

	if (!head)
		return (0);
	for (i = 0, temp = head; temp; temp = temp->next, i++)
	{
		printf("[%p] %i\n", (void *)temp, temp->n);
		if (temp->next >= temp)
			exit(98);
	}
	return (i);
}
