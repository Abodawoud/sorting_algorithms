#include "sort.h"
/**
 * merge_left_and_right - merging both partitions of the
 * array everytime again after sorting it
 * @array: .
 * @start: .
 * @mid_arr: .
 * @last: .
 * @arr: .
 */
void merge_left_and_right(int *array, size_t start,
		size_t mid_arr, size_t last, int *arr)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");

	print_array(&array[start], mid_arr - start);

	printf("[right]: ");
	print_array(&array[mid_arr], last - mid_arr);

	for (i = start, j = mid_arr; i < mid_arr && j < last; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}
	for (; i < mid_arr; i++)
		arr[k++] = array[i];
	for (; j < last; j++)
		arr[k++] = array[j];
	for (i = start, k = 0; i < last; i++)
		array[i] = arr[k++];

	printf("[Done]: ");
	print_array(&array[start], last - start);
}

/**
 * merge_recursively - helper finction that sort every part each time
 * @array: .
 * @start: .
 * @last: .
 * @arr: .
 */

void merge_recursively(int *array, size_t start, size_t last, int *arr)
{
	size_t mid_arr;

	if (last - start > 1)
	{
		mid_arr = start + (last - start) / 2;
		merge_recursively(array, start, mid_arr, arr);
		merge_recursively(array, mid_arr, last, arr);
		merge_left_and_right(array, start, mid_arr, last, arr);
	}
}
/**
 * merge_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: The Array
 * @size: The size of array
 */

void merge_sort(int *array, size_t size)
{
	int *helper_arr;

	if (!array || size < 2)
		return;
	helper_arr = malloc(4 * size);
	if (!helper_arr)
		return;
	merge_recursively(array, 0, size, helper_arr);

	free(helper_arr);
}
