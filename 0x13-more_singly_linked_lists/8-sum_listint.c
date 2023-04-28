#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list.
 * @head: head of list
 * Return: sum
 */

int sum_listint(listint_t *head)
{
	listint_t *temp;
	int sum;

	if (!head)
		return (0);
	for (sum = 0, temp = head; temp; temp = temp->next)
		sum += temp->n;
	return (sum);
}
