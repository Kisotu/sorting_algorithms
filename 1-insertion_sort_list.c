#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 *	in asceding order using the insertion list algorithm
 * @list: the doubly linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pntr;

	if (!list)
		return;

	pntr = *list;

	while (pntr)
	{
		while (pntr->next && (pntr->n > pntr->next->n))
		{
			temp = pntr->next;
			pntr->next = temp->next;
			temp->prev = pntr->prev;

			if (temp->prev)
				pntr->prev->next = temp;

			if (temp->next)
				temp->next->prev = pntr;

			pntr->prev = temp;
			temp->next = pntr;

			if (temp->prev)
				pntr = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		pntr = pntr->next;
	}
}
