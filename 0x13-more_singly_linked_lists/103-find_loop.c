#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head
 * Return: start of loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node = NULL;

	if (!head)
		return (NULL);
	for (; head; head = head->next)
	{
		if (head->next >= head)
		{
			head = head->next;
			node = head;
			return (node);
		}
	}
	return (NULL);
}
