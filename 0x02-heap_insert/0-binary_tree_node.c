#include "binary_trees.h"

/**
 * binary_tree_node - function to set the parent of a node
 *
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 *
 * gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c
 * 0-main.c 0-binary_tree_node.c -o 0-node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
