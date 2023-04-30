#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: head of list
 * @idx: index
 * @n: node value
 * Return: address of the node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp, *new;
	unsigned int i;

	if (!*head && idx)
		return (NULL);
	for (i = 0, temp = *head; idx && i < idx - 1 && temp->next; i++)
		temp = temp->next;
	if (idx)
	{
		if (i != idx - 1)
			return (NULL);
	}
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = temp->next;
		temp->next = new;
	}
	return (new);
}
