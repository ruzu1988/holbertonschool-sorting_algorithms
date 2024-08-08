#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in accending order
 * @array: order array
 * @size: size the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t idx, j;
	int temp;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		swap = 0;
		for (j = 0; j < size - idx - 1; j++)
		{
			if (array[j] == array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
