#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head
 * Return: start of loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *single, *dble;

	if (!head)
		return (NULL);
	single = dble = head;
	while (single && dble)
	{
		single = single->next;
		dble = dble->next->next;
		if (single == dble)
		{
			single = head;
			while (single != dble)
			{
				single = single->next;
				dble = dble->next;
			}
			return (single);
		}
	}
	return (NULL);
}
