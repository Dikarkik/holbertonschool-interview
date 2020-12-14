#include "lists.h"

/**
 * insert_node - function that inserts a number into a
 * sorted singly linked list.
 * @head: head of the sorted singly linked list.
 * @number: numbert to insert.
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL;
	listint_t *current = NULL;
	listint_t *previus = NULL;

	if (head == NULL || *head == NULL)
	{
		node = malloc(sizeof(listint_t));
		node->n = number;
		node->next = NULL;
		*head = node;
		return (node);
	}

	node = malloc(sizeof(listint_t));
	node->n = number;

	current = *head;

	while (current)
	{
		if (number < current->n)
			break;

		previus = current;
		current = current->next;
	}

	node->next = current;

	if (previus == NULL)
		*head = node;
	else
		previus->next = node;

	return (node);
}
