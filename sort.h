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
void swap(int *array, size_t curr, size_t next);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_first_nodes(listint_t **list, listint_t *curr, listint_t *temp);
void swap_middle_nodes(listint_t **list, listint_t *curr, listint_t *temp);
void swap_nodes(listint_t **list, listint_t *curr, listint_t *temp);
#endif
