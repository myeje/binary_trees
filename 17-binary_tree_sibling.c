#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: A pointer to the node.
 *
 * Return: NULL or sibling node.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	parent = node->parent;
	if (parent->left == node)
	{
		return (parent->right);
	}
	else if (parent->right == node)
	{
		return (parent->left);
	}

	return (NULL);
}
