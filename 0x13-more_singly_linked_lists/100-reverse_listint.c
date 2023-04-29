#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: head
 * Return: pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *before, *after;

	for (before = NULL; *head; before = *head, *head = after)
	{
		after = (*head)->next;
		(*head)->next = before;
	}
	*head = before;
	return (*head);
}
