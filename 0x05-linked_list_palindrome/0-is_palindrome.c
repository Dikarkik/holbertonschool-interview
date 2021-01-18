#include "lists.h"
#include <stdio.h>
int recursion(listint_t **node_i, listint_t *node_j);

/**
 * is_palindrome - function that checks if a
 * singly linked listis a palindrome.
 *
 * @head: double pointer to head of the singly linked list.
 *
 * An empty list is considered a palindrome.
 * gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c
 * 0-is_palindrome.c -o palindrome
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *head_copy = *head;

	if (head == NULL || *head == NULL)
		return (1);

	return (recursion(&head_copy, *head));
}

/**
 * recursion - function to compare two nodes
 *
 * @node_i: node to compare since the first node
 * @node_j: node to compare since the last node
 *
 * Return: 1 if the nodes are equal. 0 if not.
 */
int recursion(listint_t **node_i, listint_t *node_j)
{
	int prev_result;

	/* recursion */
	if (node_j->next != NULL)
		prev_result = recursion(node_i, node_j->next);
	else
		prev_result = 1;

	/* comparison */
	if (prev_result == 1 && (*node_i)->n == node_j->n)
	{
		*node_i = (*node_i)->next; /* point to the next node */
		return (1);
	}
	else
		return (0);
}
