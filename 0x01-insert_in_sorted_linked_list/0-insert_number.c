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

	if (head == NULL)
		return (NULL);

	node = malloc(sizeof(listint_t));
	node->n = number;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	current = *head;

	while (1)
	{
		previus = current;
		current = current->next;

		if (current == NULL || number < current->n)
			break;
	}

	node->next = current;

	if (previus == NULL)
		*head = node;
	else
		previus->next = node;

	return (node);
}
