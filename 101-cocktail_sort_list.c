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
	int flag, list_size, size, list_size1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	list_size = calc_list_size(*list);
	list_size1 = list_size;
	curr = *list;
	while (curr)
	{
		flag = 0;
		curr2 = curr;
		size = list_size1--;
		while (curr2->next && size--)
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
		size = list_size1 + 1;
		while (temp->prev && size--)
		{
			if (temp->n < temp->prev->n)
			{
				*list = swap_list(*list, temp);
				print_list(*list);
				flag = 1;
			} else
				temp = temp->prev;
		}
		if (curr->next->n < curr->n)
			curr = curr; else
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

	/* Initialize 'curr' as the head of the list and 'cnt' as 0 */
	curr = list;
	cnt = 0;

	/* Traverse the list and increment 'cnt' for each node */
	while (curr)
	{
		curr = curr->next;
		cnt++;
	}

	/* Return the total number of nodes,which represents the size of the list*/
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

	/* Initialize 'curr' as the head of the list */
	curr = list;

	/* Traverse the list until the last node is reached */
	while (curr->next)
	{
		curr = curr->next;
	}

	/* Return the last node of the list */
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

	/* Store the previous node of the current node in 'temp' */
	temp = curr2->prev;

	/* Update pointers to perform the node swap */
	curr2->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = curr2;
	temp->next = curr2->next;
	if (curr2->next)
		curr2->next->prev = temp;

	curr2->next = temp;
	temp->prev = curr2;

	/* Update the 'list' pointer if the current node is now the first node */
	if (!curr2->prev)
		list = curr2;

	/* Return the updated list (the last node remains unchanged) */
	return (list);
}
