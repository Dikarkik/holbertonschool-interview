#include "binary_trees.h"

void get_last_leaf(heap_t *node, int *stop_recursion,
	heap_t **last_leaf, int *max_depth, int current_depth);
void replace_and_delete_root(heap_t **root, heap_t *last_leaf);
void heapify_root(heap_t **root);
void swap_nodes(heap_t *node_1, heap_t *node_2);

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the heap
 *
 * Return: the value stored in the root node. If the function fails, return 0
 *
 * gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c
 * 0-heap_extract.c binary_tree_print.c -L. -lheap
 */
int heap_extract(heap_t **root)
{
	int max_value = 0;
	heap_t *last_leaf = NULL;
	int max_depth = 0;
	int stop_recursion = 0;

	if (root == NULL || *root == NULL)
		return (max_value);

	max_value = (*root)->n;

	get_last_leaf(*root, &stop_recursion, &last_leaf, &max_depth, 1);

	replace_and_delete_root(root, last_leaf);

	heapify_root(root);

	return (max_value);
}

/**
 * get_leaf - function to find the leaf where the node must be interted
 *
 * @node: is a pointer to the root node of the Heap
 * @stop_recursion: is a flag to stop the recursion, 0 to continue, 1 to stop
 * @last_leaf: is a double pointer to the leaf, thi is NULL, then becomes the
 * leftmost leaf, then becomes the leaf found in the previous level (if exists)
 * @max_depth: is the max depth of the Heap, start in 0,
 * then becomes in the depth of the leftmost leaf
 * @current_depth: is the current depth of the Heap during recursion
 */
void get_last_leaf(heap_t *node, int *stop_recursion,
	heap_t **last_leaf, int *max_depth, int current_depth)
{
	if (*stop_recursion == 1)
		return;

	/* if 'node' is a leaf */
	if (node->left == NULL && node->right == NULL)
	{
		/* if this is the first leaf (leftmost) */
		if (*last_leaf == NULL)
		{
			*last_leaf = node;
			*max_depth = current_depth;
			return;
		}
		/* if this leaf is on max_depth-1 the recursion must finish */
		else if (current_depth < *max_depth)
		{
			*stop_recursion = 1;
			return;
		}
		/* if this leaf is on max_depth */
		else if (current_depth == *max_depth)
		{
			*last_leaf = node;
			return;
		}
	}

	/* if 'node' isn't a leaf */
	if (node->left)
		get_last_leaf(node->left, stop_recursion, last_leaf, max_depth, current_depth + 1);
	if (node->right)
		get_last_leaf(node->right, stop_recursion, last_leaf, max_depth, current_depth + 1);
}

/**
 * replace_and_delete_root - replace and delete root
 *
 * @root: is a double pointer to the root node of the heap
 * @last_leaf: node to replace the deleted root
 */
void replace_and_delete_root(heap_t **root, heap_t *last_leaf)
{
	heap_t *old_root = *root;

	/* clean child pointer in last_leaf->parent before go away */
	if (last_leaf == last_leaf->parent->right)
		last_leaf->parent->right = NULL;
	else
		last_leaf->parent->left = NULL;

	/* set new root */
	last_leaf->parent = NULL;
	last_leaf->left = (*root)->left;
	last_leaf->right = (*root)->right;
	*root = last_leaf;

	/* update parent pointer in root childrens */
	(*root)->left->parent = *root;
	(*root)->right->parent = *root;

	free(old_root);
}

/**
 * heapify_root - move the root node to rearrange the heap tree
 *
 * @root: is a double pointer to the root node of the heap
 */
void heapify_root(heap_t **root)
{
	heap_t *node_1 = *root;
	heap_t *node_2 = NULL;
	int is_first_iteration = 1;

	while (node_1->left || node_1->right)
	{
		/* stops when there isn't childs to check */
		if (node_1->left == NULL && node_1->right == NULL)
			break;

		/* stops when there are two childs but isn't necessary to swap */
		if ((node_1->left && node_1->right) && (node_1->n >= node_1->left->n && node_1->n >= node_1->right->n))
			break;

		/* stops when there are one child but isn't necessary to swap */
		if (node_1->right == NULL && node_1->n >= node_1->left->n)
			break;

		/* ---SWAP IS REQUIRED--- */

		/* if must swap left child */
		if (node_1->right == NULL || node_1->left->n >= node_1->right->n)
			node_2 = node_1->left;

		/* if must swap right child */
		else if (node_1->right != NULL && node_1->left->n < node_1->right->n)
			node_2 = node_1->right;

		if (is_first_iteration)
		{
			/* set the new root */
			*root = node_2;
			is_first_iteration = 0;
		}

		swap_nodes(node_1, node_2);
	}
}

/**
 * swap_nodes - make node_2 the parent of node_1
 *
 * @node_1: pointer to node 1
 * @node_2: pointer to node 2
 */
void swap_nodes(heap_t *node_1, heap_t *node_2)
{
	heap_t *left_grandson, *right_grandson = NULL;

	left_grandson = node_2->left;
	right_grandson = node_2->right;

	/* node_2 parent */
	if (node_1->parent == NULL)
		node_2->parent = NULL;
	else
	{
		node_2->parent = node_1->parent;

		if (node_2->parent->left == node_1)
			node_2->parent->left = node_2;
		else
			node_2->parent->right = node_2;
		}

	/* node_2 childs */
	if (node_2 == node_1->left)
	{
		node_2->left = node_1;
		node_2->right = node_1->right;
	}
	else
	{
		node_2->left = node_1->left;
		node_2->right = node_1;
	}

	if (node_2->left)
		node_2->left->parent = node_2;
	if (node_2->right)
		node_2->right->parent = node_2;

	/* node_1 parent */
	node_1->parent = node_2;

	/* node_1 childs */
	node_1->left = left_grandson;
	if (node_1->left)
		node_1->left->parent = node_1;

	node_1->right = right_grandson;
	if (node_1->right)
		node_1->right->parent = node_1;
}
