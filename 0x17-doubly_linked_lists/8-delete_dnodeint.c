#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: head
 * @index: index of the list what node should be deleted.
 * Return: -1 or 1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	size_t len = dlistint_len(*head);
	int i;
	dlistint_t *temp;

	if (!(*head) || len < index)
		return (-1);
	temp = *head;
	if (len == 1 && index == 0)
	{
		free_dlistint(*head);
		*head = NULL;
	}
	else if (!index)
	{
		(*head)->next->prev = NULL;
		(*head) = (*head)->next;
	}
	else if (index == len)
	{
		for (temp = *head; temp->next; temp = temp->next)
			;
		temp->prev->next = NULL;
		temp = temp->prev;
	}
	else
	{
		for (temp = *head, i = 0; i < (int)index; i++, temp = temp->next)
			;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	return (1);
}

/**
 * dlistint_len - returns number of elements
 * @h: head
 * Return: int number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i;

	for (i = 0; h; h = h->next, i++)
		;
	return (i);
}
