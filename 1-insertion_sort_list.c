#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *sorted;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		sorted = curr;
		curr = curr->next;

		while (sorted && sorted->prev && sorted->prev->n > sorted->n)
		{
			temp = sorted->prev;
			sorted->prev = temp->prev;
			temp->next = sorted->next;

			if (temp->prev)
				temp->prev->next = sorted;

			if (sorted->next)
				sorted->next->prev = temp;

			temp->prev = sorted;
			sorted->next = temp;

			if (!sorted->prev)
				*list = sorted;

			print_list(*list);
		}
	}
}
