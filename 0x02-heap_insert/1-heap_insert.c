#include "binary_trees.h"

void get_leaf(heap_t *node, int *stop_recursion,
			  heap_t **leaf, int *max_depth, int current_depth);
void move_new_node(heap_t **root, heap_t *new_node);

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = malloc(sizeof(heap_t));
	heap_t *leaf = NULL;
	int max_depth = 0;
	int stop_recursion = 0;

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (root == NULL)
	{
		root = &new_node;
		return (new_node);
	}

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* look for the leaf and save them in 'leaf' */
	get_leaf(*root, &stop_recursion, &leaf, &max_depth, 1);

	if (leaf->left == NULL)
		leaf->left = new_node;
	else
		leaf->right = new_node;

	new_node->parent = leaf;

	move_new_node(root, new_node);

	return (new_node);
}

/**
 * get_leaf - function to find the leaf where the node must be interted
 *
 * @node: is a pointer to the root node of the Heap
 * @stop_recursion: is a flag to stop the recursion, 0 to continue, 1 to stop
 * @leaf: is a double pointer to the leaf, thi is NULL, then becomes the
 * leftmost leaf, then becomes the leaf found in the previous level (if exists)
 * @max_depth: is the max depth of the Heap, start in 0,
 * then becomes in the depth of the leftmost leaf
 * @current_depth: is the current depth of the Heap during recursion
 */
void get_leaf(heap_t *node, int *stop_recursion,
			  heap_t **leaf, int *max_depth, int current_depth)
{
	if (*stop_recursion == 1)
		return;

	/* if 'node' is a leaf */
	if (node->left == NULL || node->right == NULL)
	{
		/* if this is the first leaf (leftmost) */
		if (*leaf == NULL)
		{
			*leaf = node;
			*max_depth = current_depth;
		}
		/* if a leaf is found in the previous level (tree depth) */
		else if (current_depth < *max_depth)
		{
			*leaf = node;
			*stop_recursion = 1;
		}
	}
	else
	{
		get_leaf(node->left, stop_recursion, leaf, max_depth, current_depth + 1);
		get_leaf(node->right, stop_recursion, leaf, max_depth, current_depth + 1);
	}
}

/**
 * move_new_node - function that moves the new node into a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the Heap
 * @new_node: is the node to move
 */
void move_new_node(heap_t **root, heap_t *new_node)
{
	heap_t *parent = NULL, *left_child = NULL, *right_child = NULL;

	while (new_node->parent)
	{
		if (new_node->n < new_node->parent->n)
			break;

		parent = new_node->parent;
		left_child = new_node->left;
		right_child = new_node->right;

		/* grandparent becomes the parent of 'new_node' */
		if (new_node->parent->parent)
		{
			if (new_node->parent->parent->left == parent)
				new_node->parent->parent->left = new_node;
			else
				new_node->parent->parent->right = new_node;

			new_node->parent = new_node->parent->parent;
		}
		else
		{
			new_node->parent = NULL;
			*root = new_node;
		}

		/* 'new_node' replace his parent */
		/* - search the brother of 'new node' and set them like a child */
		/* - set his parent like a child */
		if (parent->left == new_node)
		{
			if (parent->right != NULL)
			{
				new_node->right = parent->right;
				new_node->right->parent = new_node;
			}

			new_node->left = parent;
			new_node->left->parent = new_node;
		}
		else
		{
			new_node->left = parent->left;
			new_node->left->parent = new_node;

			new_node->right = parent;
			new_node->right->parent = new_node;
		}

		/* The parent replace 'new_node' */
		parent->left = left_child;
		if (parent->left)
			parent->left->parent = parent;

		parent->right = right_child;
		if (parent->right)
			parent->right->parent = parent;
	}
}
