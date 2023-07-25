#ifndef SORT_H
#define SORT_H
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void swapp(int *array, size_t size, int i, int j);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int find_pivot(int *array, size_t size, int start, int last);
int find_pivot_with_hoare(int *array, size_t size, size_t start, size_t last);
void make_partitions_with_pivot(int *array, size_t size, int start, int last);
void make_partitions_with_pivot_hoare(int *array, size_t size,
				size_t start, size_t last);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void heap_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
listint_t *get_last_node(listint_t *list);
listint_t *swap_list(listint_t *list, listint_t *curr2);
void cocktail_sort_list(listint_t **list);
int calc_list_size(listint_t *list);
void merge_sort(int *array, size_t size);
void _swapp(int *array, int i, int j);
void radix_sort(int *array, size_t size);
#endif
