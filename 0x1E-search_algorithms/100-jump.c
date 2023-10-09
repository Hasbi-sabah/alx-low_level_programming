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
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if ((i + jump >= (int)size || array[i + jump] >= value) && !flag)
		{
			prev = i;
			i += jump;
			printf("Value found between indexes [%d] and [%d]\n", prev, i);
			if (i < (int)size)
				size = i + 1;
			i = prev - 1;
			jump = 1;
			flag++;
		}
		else if (array[i] == value)
			return (i);
		prev = i;
	}
	return (-1);
}
