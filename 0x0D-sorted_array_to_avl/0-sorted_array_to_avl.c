#include <stdlib.h>
#include "binary_trees.h"

avl_t *recursion(int i_left, int i_right, avl_t *parent, int *array);
avl_t *create_node(int num, avl_t *parent);

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 *
 * MORE:
 * - You can assume there will be no duplicate value in the array
 * - You are not allowed to rotate
 * - You can only have 3 functions in your file
 *
 * gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c
 * 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (array == NULL)
		return (NULL);

	head = recursion(0, size - 1, NULL, array);

	return (head);
}

/**
 * recursion - Method to define the next node of the tree.
 * Then, call 'recursion' for left and right children.
 *
 * @i_left: index range from left
 * @i_right: index range until right
 * @parent: parent of the new node
 * @array: array with values of the tree
 *
 * Return: pointer to the new node
 */
avl_t *recursion(int i_left, int i_right, avl_t *parent, int *array)
{
	int i_middle;
	avl_t *node;

	i_middle = (i_left + i_right) / 2;

	node = create_node(array[i_middle], parent);

	if (i_left <= i_middle - 1)
		node->left = recursion(i_left, i_middle - 1, node, array);
	if (i_right >= i_middle + 1)
		node->right = recursion(i_middle + 1, i_right, node, array);

	return (node);
}

/**
 * create_node - create a node with value and parent
 *
 * @num: value
 * @parent: parent of the node
 *
 * Return: pointer to the new node
 */
avl_t *create_node(int num, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));

	node->n = num;
	node->left = NULL;
	node->right = NULL;

	if (parent != NULL)
		node->parent = parent;

	return (node);
}
