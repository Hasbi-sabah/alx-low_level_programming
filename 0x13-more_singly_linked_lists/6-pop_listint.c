#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: head of list
 * Return: the head node’s data (n).
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int nholder;

	if (!*head)
		return (0);
	nholder = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (nholder);
}
