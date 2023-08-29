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
	binary_tree_t *tmp;

	ptr = malloc(sizeof(binary_tree_t));
	if (!ptr || !parent)
	{
		return (NULL);
	}
	ptr->n = value;
	ptr->left = NULL;
	ptr->right = NULL;

	if (parent->right != NULL)
	{
		tmp = parent->right;
		parent->right = ptr;
		ptr->right = tmp;
		tmp->parent = ptr;
	}
	else
		parent->right = ptr;

	return (ptr);
}
