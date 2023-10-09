#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorith
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (interpolation_helper(array, 0, size - 1, value));
}

/**
 * interpolation_helper - recursive function
 *
 * @array: array
 * @min: min
 * @max: max
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int interpolation_helper(int *array, int min, int max, int value)
{
	size_t pos = min + (((double)(max - min) /
		(array[max] - array[min])) * (value - array[min]));

	if ((int)pos > max)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}
	if (min <= max)
	{
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] > value)
			return (interpolation_helper(array, 0, pos - 1, value));
		else if (array[pos] < value)
			return (interpolation_helper(array, pos + 1, max, value));
		else if (array[pos] == value)
			return (pos);
	}
	return (-1);
}
