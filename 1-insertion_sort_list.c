#include "sort.h"

/**
 * insertion_sort_list - Sorts a list using insertion
 * sort algorithm.
 * @list: A doubly link list to be sorted.
 * Return: Nothing.
 *
 * The swapping approach visualized as shown below:
 *
 * For each node before swapping:
 * [i] <-> [prev] <-> [node] <-> [j]
 * node->next = j
 * node->prev = prev
 * prev->next = node
 * prev->prev = i
 * i->next = prev
 * j->prev = node
 *
 * For each node after swapping:
 * [i] <-> [node] <-> [prev] <-> [j]
 * node->next = prev
 * node->prev = i
 * prev->next = j
 * prev->prev = node
 * i->next = node
 * j->prev = prev
 *
 * Logic to condiser for x and y while swapping nodes
 * provided that they are NULL pointers.
 * if i == NULL don't update i
 * if j == NULL don't update j
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *main, *i, *prev, *node, *j;

	if (list == NULL)
		return;

	main = *list;

	while (main != NULL)
	{
		node = main;
		while (node->prev != NULL)
		{
			prev = node->prev;
			i = prev->prev;
			j = node->next;

			if (i == NULL)
				*list = prev;
			if (node->nd < prev->nd)
			{
				node->next = prev;
				node->prev = i;
				prev->next = j;
				prev->prev = node;

				if (i != NULL)
					i->next = node;
				if (j != NULL)
					j->prev = prev;

				if (node->prev == NULL)
					*list = node;

				print_list(*list);
				continue;
			}
			node = node->prev;
		}
		main = main->next;
	}
}
