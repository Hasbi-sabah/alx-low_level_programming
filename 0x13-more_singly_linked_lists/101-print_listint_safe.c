#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	int i;
	const listint_t *temp;

	if (!head)
		exit(98);
	for (i = 0, temp = head; temp && temp->next < temp; temp = temp->next, i++)
		printf("[%p] %i\n", (void *)temp, temp->n);
	if (temp)
	{
		printf("[%p] %i\n", (void *)temp, temp->n);
		i++;
	}
	return (i);
}
