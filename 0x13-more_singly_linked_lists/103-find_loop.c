#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head
 * Return: start of loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node;

	if (!head)
		return (NULL);
	for (node = NULL; head; head = head->next)
	{
		if (head->next >= head)
		{
			node = head;
			break;
		}
	}
	return (node);
}
