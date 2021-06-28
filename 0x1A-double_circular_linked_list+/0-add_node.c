#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	return (add_node(list, str, 0));
}

/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	return (add_node(list, str, 1));
}

/**
 * add_node - Add a new node to the beginning/end
 * of a double circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * @replace_root: if it's 1, place the new node at the beginning,
 * otherwise place the node at the end.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node(List **list, char *str, int replace_root)
{
	List *node = NULL;

	if (list == NULL)
		return (NULL);

	node = malloc(sizeof(List));

	if (node == NULL)
		return (NULL);

	node->str = str;

	/* if this is the first node */
	if (*list == NULL)
	{
		*list = node;
		node->next = node;
		node->prev = node;
		return (node);
	}

	node->next = *list;
	node->prev = (*list)->prev;

	(*list)->prev->next = node;

	(*list)->prev = node;

	if (replace_root == 1)
		*list = node;

	return (node);
}
