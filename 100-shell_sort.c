#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap;

	if (array && size > 1)
	{
		gap = 1;
		while (gap < size) {
			gap = 3 * gap + 1;
		}
		gap = (gap - 1) / 3;
		for (; gap > 0; gap = (gap - 1) / 3)
		{
			for (i = gap; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
					array[j] = array[j - gap];
				array[j] = temp;
			}
			print_array(array, size);
		}
	}
}
