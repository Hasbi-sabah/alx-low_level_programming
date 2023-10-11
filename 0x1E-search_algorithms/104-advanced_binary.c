#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Binary search algorith
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (advanced_binary_helper(array, 0, size - 1, value));
}

/**
 * advanced_binary_helper - recursive function
 *
 * @array: array
 * @min: min
 * @max: max
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int advanced_binary_helper(int *array, int min, int max, int value)
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
			return (advanced_binary_helper(array, min, mid, value));
		else if (array[mid] < value)
			return (advanced_binary_helper(array, mid + 1, max, value));
		else if (array[mid] == value && array[mid - 1] == value)
			return (advanced_binary_helper(array, min, mid, value));
		else if (array[mid] == value)
			return (mid);
	}
	return (-1);
}
