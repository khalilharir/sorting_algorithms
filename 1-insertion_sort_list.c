#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @p: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **p, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*p = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *     
 * @l: A pointer for doubly-linked list of integers.
 *
 * Description: prints after swapping.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
