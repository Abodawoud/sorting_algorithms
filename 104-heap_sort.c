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
 * get_the_root_and_children - puts every elemnts in the right position
 * @array: the array
 * @size: size of array
 * @n: the size index to use .
 * @i: the index of the parent.
 */
void get_the_root_and_children(int *array, size_t size, int n, int i)
{
	int greater = i, left_child = 2 * i + 1, right_child = 2 * i + 2;

	if (left_child < n && array[left_child] > array[greater])
		greater = left_child;
	if (right_child < n && array[right_child] > array[greater])
		greater = right_child;
	if (greater != i)
	{
		swapp(array, size, i, greater);
		get_the_root_and_children(array, size, n, greater);
	}
}
/**
 * heap_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array
 * @size: the size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		get_the_root_and_children(array, size, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swapp(array, size, 0, i);
		get_the_root_and_children(array, size, i, 0);
	}
}
