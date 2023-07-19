#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * swap - Function that swap
 *
 * @array: The Array
 * @size: The size of array
 */

void swap(int *array, size_t curr, size_t next)
{
	size_t temp;

	temp = array[curr];
	array[curr] = array[next];
	array[next] = temp;
}
