#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - function that finds the loop in a linked list.
 *
 * @head: first node of the list.
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop.
 *
 * gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node_1 = NULL;
	listint_t *node_2 = NULL;

	if (head)
		node_1 = head->next;
	else
		return (NULL);

	if (head->next)
		node_2 = head->next->next;

	while (node_1 != NULL && node_2 != NULL)
	{
		/* If a loop is detected, find the node where the loop starts */
		if (node_1->n == node_2->n)
		{
			node_1 = head;

			while (node_1->n != node_2->n)
			{
				node_1 = node_1->next;
				node_2 = node_2->next;
			}
			return (node_1);
		}

		/* move node positions */
		node_1 = node_1->next;

		if (node_2->next)
			node_2 = node_2->next->next;
		else
			break;
	}

	return (NULL);
}
