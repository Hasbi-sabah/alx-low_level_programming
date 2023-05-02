#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp1, *temp2;
	size_t i = 0, j;

	temp1 = head;
	while (temp1)
	{
		printf("[%p] %d\n", (void *)temp1, temp1->n);
		i++;
		temp1 = temp1->next;
		for (j = 0, temp2 = head; j < i; temp2 = temp2->next, j++)
		{
			if (temp1 == temp2)
			{
				printf("-> [%p] %d\n", (void *)temp1, temp1->n);
				return (i);
			}
		}
		if (!head)
			exit(98);
	}
	return (i);
}
