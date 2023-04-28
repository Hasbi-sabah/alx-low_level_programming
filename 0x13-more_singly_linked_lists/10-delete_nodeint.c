#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index.
 * @head: head of list
 * @index: index
 * Return: 1 or -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *del;
	unsigned int i;

	if (!*head)
		return (-1);
	for (i = 0, temp = *head; i < index - 1 && temp->next; i++)
		temp = temp->next;
	if (!temp->next && index && i != index - 1)
		return (-1);
	if (!index)
	{
		del = *head;
		*head = (*head)->next;
	}
	else
	{
		del = temp->next;
		temp->next = del->next;
	}
	free(del);
	return (1);
}
