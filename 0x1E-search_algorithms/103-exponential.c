#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int exponential_search(int *array, size_t size, int value)
{
	int i, prev;

	if (!array || size == 0 || value < array[0])
		return (-1);
	for (i = 1, prev = 1; 1; i *= 2)
	{
		if (i >= (int)size || array[i] >= value)
		{
			if (i >= (int)size)
				i = size - 1;
			printf("Value found between indexes [%d] and [%d]\n", prev, i);
			return (binary_helper(array, prev, i, value));
		}
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		prev = i;
	}
	return (-1);
}
/**
 * binary_helper - recursive function
 *
 * @array: array
 * @min: min
 * @max: max
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int binary_helper(int *array, int min, int max, int value)
{
	int mid = (max + min) / 2;
	int i;

	if (min <= max)
	{
		printf("Searching in array: ");
		for (i = min; i <= max; i++)
		{
			printf("%d", array[i]);
			if (i < max)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] > value)
			return (binary_helper(array, min, mid - 1, value));
		else if (array[mid] < value)
			return (binary_helper(array, mid + 1, max, value));
		return (mid);
	}
	return (-1);
}
