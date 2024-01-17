#include "sort.h"
/**
 * insertion_sort_list - A void
 * @list: A listint_t
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
