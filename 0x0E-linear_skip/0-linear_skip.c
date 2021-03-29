#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @head: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 *
 * Return: a pointer on the first node where value is located
 * If value is not present in list or if head is NULL, return NULL
 *
 * gcc -Wall -Wextra -Werror -pedantic *.c -lm -o 0-linear_skip
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *start_node = NULL;
	skiplist_t *end_node = NULL;

	if (head == NULL)
		return (NULL);

	start_node = head;
	end_node = get_skip_node(start_node);

	/* get range to find 'value' */
	while (end_node->next)
	{
		printf("Value checked at index [%li] = [%d]\n",
		end_node->index, end_node->n);

		if (value > end_node->n)
		{
			start_node = end_node;
			end_node = get_skip_node(start_node);
			continue;
		}
		break;
	}

	printf("Value found between indexes [%li] and [%li]\n",
	start_node->index, end_node->index);

	/* get node with 'value' */
	while (start_node)
	{
		printf("Value checked at index [%li] = [%d]\n",
		start_node->index, start_node->n);

		if (value == start_node->n)
			break;

		start_node = start_node->next;
	}

	return (start_node);
}

/**
 * get_skip_node - get the skip node,
 * or tail of list when skip node is null.
 *
 * @start_node: pointer to node
 *
 * Return: pointer to the skip node
 */
skiplist_t *get_skip_node(skiplist_t *start_node)
{
	if (start_node->express)
		return (start_node->express);

	while (start_node->next)
		start_node = start_node->next;

	return (start_node);
}
