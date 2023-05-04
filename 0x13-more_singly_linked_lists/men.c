#include "lists.h"

/**
 * floyd_loop - check if the list has a loop in it.
 * @head: the linked list.
 * Return: 0 or number of nodes.
 */

size_t floyd_loop(const listint_t *head)
{
	const listint_t *ptr_s, *ptr_f;
	size_t i = 0;

	if (head == NULL || head->next == NULL)
		return (0);
	ptr_s = head->next;
	ptr_f = head->next->next;
	i = 1;
	while (ptr_f)
	{
		if (ptr_s == ptr_f)
		{
			ptr_s = head;
			while (ptr_s != ptr_f)
			{
				i++;
				ptr_s = ptr_s->next;
				ptr_f = ptr_f->next;
			}
			ptr_s = ptr_s->next;
			while (ptr_s != ptr_f)
			{
				i++;
				ptr_s = ptr_s->next;
			}
			return (i);
		}
		ptr_s = ptr_s->next;
		ptr_f = ptr_f->next->next;
	}
	return (0);
}


/**
 * print_listint_safe - print the element of a linked list.
 * @head: the first element of the list.
 * Return: number of elements of the lists.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0, loops;

	loops = floyd_loop(head);
	if (loops == 0)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			loops++;
			head = head->next;
		}
	}
	else
	{
		while (i < loops)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			i++;
		}

		printf("->[%p] %d\n", (void *)head, head->n);
	}
	printf("%li\n", loops);
	return (loops);
}
