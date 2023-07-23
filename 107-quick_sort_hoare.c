#include "sort.h"
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
 * find_pivot - a function that is used to find the pivot
 * @array: arr of ints
 * @size: Size of array
 * @start: first index in the array or sub-array
 * @last: last index in the array or sub-array
 * Return: the pivot's index
 */
int find_pivot(int *array, size_t size, size_t start, size_t last)
{
	int pivot = array[last], i = start - 1, j = last + 1;

	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		swapp(array, size, j, i);
	}
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
void make_partitions_with_pivot(int *array, size_t size,
				size_t start, size_t last)
{
	size_t border;

	if (start < last)
	{
		border = find_pivot(array, size, start, last);
		make_partitions_with_pivot(array, size, start, border);
		make_partitions_with_pivot(array, size, border + 1, last);
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
	if (!array || size < 2)
		return;

	make_partitions_with_pivot(array, size, 0, size - 1);
}
