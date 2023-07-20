#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: The Array
 * @size: The size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size; j++)
	{
		swapped = 0;
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
