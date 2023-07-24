#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: list of numbers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *curr2, *temp;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = *list;
	while (curr)
	{
		flag = 0;
		curr2 = curr;
		while (curr2->next)
		{
			if (curr2->n > curr2->next->n)
			{
				*list = swap_list(*list, curr2->next);
				print_list(*list);
				flag = 1;
			} else
				curr2 = curr2->next;
		}
		if (!flag)
			break;
		temp = get_last_node(*list);
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				*list = swap_list(*list, temp);
				print_list(*list);
				flag = 1;
			} else
				temp = temp->prev;
		}
		if (curr->next != NULL && curr->next->n < curr->n)
			curr = curr;
		else
			curr = curr->next;
	}
}
/**
 * swap - swap two numbers
 *
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
/**
 * calc_list_size - calculate the size of the list.
 *
 * @list: list of numbers.
 *
 * Return: the size of the list.
 */
int calc_list_size(listint_t *list)
{
	listint_t *curr;
	int cnt;

	curr = list;
	cnt = 0;

	while (curr)
	{
		curr = curr->next;
		cnt++;
	}
	return (cnt);
}

/**
 * get_last_node - get the last node of the list.
 *
 * @list: list of numbers.
 *
 * Return: the last node of the list.
 */
listint_t *get_last_node(listint_t *list)
{
	listint_t *curr;

	curr = list;

	while (curr->next)
	{
		curr = curr->next;
	}

	return (curr);
}


/**
 * swap_list - swap the node with its previous node.
 *
 * @list: list of numbers.
 * @curr2: the node to swap with its previous node.
 *
 * Return: the last node of the list.
 */
listint_t *swap_list(listint_t *list, listint_t *curr2)
{
	listint_t *temp;

	temp = curr2->prev;

	curr2->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = curr2;
	temp->next = curr2->next;
	if (curr2->next)
		curr2->next->prev = temp;

	curr2->next = temp;
	temp->prev = curr2;

	if (!curr2->prev)
		list = curr2;

	return (list);
}
