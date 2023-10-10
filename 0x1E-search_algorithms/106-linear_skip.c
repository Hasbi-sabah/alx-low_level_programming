#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: linked list
 * @value: value
 *
 * Return: head if found and NULL if not
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int flag = 0;
	skiplist_t *head, *prev;

	if (!list)
		return (NULL);
	for (prev = list, head = list->express; 1;)
	{
		if (!head && flag)
			break;
		if ((!head || head->n > value) && !flag)
		{
			if (!head)
			{
				for (head = prev; head->next; head = head->next)
					;
			}
			else
				printf("Value checked array[%ld] = [%d]\n", head->index, head->n);
			printf("Value found between indexes [%ld] and [%ld]\n",
					prev->index, head->index);
			head = prev;
			prev = head;
			flag++;
			continue;
		}
		else if (head->n == value)
		{
			printf("Value checked array[%ld] = [%d]\n", head->index, head->n);
			return (head);
		}
		printf("Value checked array[%ld] = [%d]\n", head->index, head->n);
		prev = head;
		if (!flag)
			head = head->express;
		else
			head = head->next;
	}
	return (NULL);
}
