#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int jump_search(int *array, size_t size, int value)
{
	int i, jump = sqrt(size), prev, flag = 0;

	if (!array)
		return (-1);
	for (i = 0, prev = 0; i < (int)size; i += jump)
	{
		if (array[i] >= value && !flag)
		{
			printf("Value found between indexes [%d] and [%d]\n", prev, i);
			size = i + 1;
			i = prev;
			jump = 1;
			flag++;
		}
		else if (array[i] == value)
		{
			printf("Value checked array[%d] = [%d]\n", i, array[i]);
			return (i);
		}
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		prev = i;
	}
	return (-1);
}
