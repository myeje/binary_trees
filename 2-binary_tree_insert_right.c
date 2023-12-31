#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child.
 * @parent: A pointer to the node to insert the right-child.
 * @value: value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr;

	if (!parent)
		return (NULL);
	ptr = malloc(sizeof(binary_tree_t));
	if (!ptr)
		return (NULL);

	ptr->n = value;
	ptr->parent = parent;
	ptr->left = NULL;

	if (parent->right)
	{
		ptr->right = parent->right;
		parent->right->parent = ptr;
	}
	else
	{
		ptr->right = NULL;
	}
	parent->right = ptr;

	return (ptr);
}
