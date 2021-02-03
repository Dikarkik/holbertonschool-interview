#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 *
 * @list: head of the linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 *
 * gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c
 * 0-linked_lists.c -o cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *node_1 = list;
	listint_t *node_2 = list;
	int jumps = 0;

	while (node_1 != NULL && node_2 != NULL)
	{
		/* move node_2 */
		jumps = 0;

		for (jumps = 0; jumps < 2; jumps++)
			if (node_2 != NULL)
				node_2 = node_2->next;

		/* check if there is a cycle */
		if (node_1 == node_2)
			return (1);

		/* move node_1 */
		node_1 = node_1->next;
	}

	return (0);
}
