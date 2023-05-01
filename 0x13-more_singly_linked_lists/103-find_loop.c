#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head
 * Return: start of loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *single, *dble;
	int flag = 0;

	if (!head)
		return (NULL);
	single = dble = head;
	while (single && dble)
	{
		if (!flag)
		{
			single = single->next;
			dble = dble->next->next;
		}
		if (flag)
		{
			single = single->next;
			dble = dble->next;
		}
		if (single == dble)
		{
			if (flag)
				return (single);
			single = head;
			flag = 1;
		}
	}
	return (NULL);
}
