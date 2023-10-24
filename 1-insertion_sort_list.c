#include "sort.h"
/**
 * insertion_sort_list - The algorithm for the insertion sort.
 * @list : Pointer to Pointer to head of doubly linked list.
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *tmp_next, *tmp_prev, *tmp, *pp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (tmp != NULL)
	{
		p = (*tmp).p;
		while (p != NULL)
		{
			if ((*tmp).n < (*p).n)
			{
				tmp_next = (*tmp).next;
				tmp_prev = (*tmp).p;
				(*tmp).next = p;
				pp = (*p).p;
				if (pp == NULL)
					*list = tmp;
				else
					(*pp).next = tmp;
				(*tmp).p = pp;
				(*p).p = tmp;
				if (tmp_next != NULL)
					(*tmp_next).p = tmp_prev;
				(*tmp_prev).next = tmp_next;
				print_list(*list);
			}
			p = (*p).p;
		}
		tmp = (*tmp).next;
	}
}

