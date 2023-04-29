#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: head of list
 * @index: index
 * Return: address of the node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp;
	unsigned int i;

	if (!head)
		return (NULL);
	for (i = 0, temp = head; i < index && temp->next; temp = temp->next, i++)
		;
	if (!temp->next && index > i)
		return (NULL);
	return (temp);
}
