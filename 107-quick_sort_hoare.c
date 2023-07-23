#include "sort.h"

/**
 * find_pivot - a function that is used to find the pivot
 * @array: arr of ints
 * @size: Size of array
 * @start: first index in the array or sub-array
 * @last: last index in the array or sub-array
 * Return: the pivot's index
 */
int find_pivot(int *array, size_t size, int start, int last)
{
	int i = start - 1, j = start;

	for (; j < last; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			swapp(array, size, i, j);
		}
	}
	swapp(array, size, i + 1, last);
	return (i + 1);
}

/**
 * make_partitions_with_pivot - a function that is
 * used to make partitions with the pivot [low, piv, high]
 * @array: arr of ints
 * @size: Size of array
 * @start: first index in the array or sub-array
 * @last: last index in the array or sub-array
 * Return: void
 */
void make_partitions_with_pivot(int *array, size_t size, int start, int last)
{
	int pivot;

	if (start > last)
		return;

	pivot = find_pivot(array, size, start, last);
	make_partitions_with_pivot(array, size, start, pivot - 1);
	make_partitions_with_pivot(array, size, pivot + 1, last);
}
/**
 * swapp - swaps two eles
 *
 * @array: array of ints
 * @size: size of th arr
 * @i: first idx
 * @j: sec idx
 * Return: void
 */
void swapp(int *array, size_t size, int i, int j)
{
	int temp;

	temp = array[j];
	if (array[i] != array[j])
	{
		array[j] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: The Array
 * @size: The size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array)
		make_partitions_with_pivot(array, size, 0, size - 1);
}
