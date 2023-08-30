#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr;
	binary_tree_t *tmp;

	if (!parent)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(binary_tree_t));
	if (!ptr)
	{
		return (NULL);
	}
	ptr->n = value;
	ptr->left = NULL;
	ptr->right = NULL;

	if (parent->left != NULL)
	{
		tmp = parent->left;
		parent->left = ptr;
		ptr->left = tmp;
	}
	else
		parent->left = ptr;


	return (ptr);
}
