#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: A pointer to the node.
 *
 * Return: NULL or uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	parent = node->parent->parent;
	if (parent->left->left == node || parent->left->right == node)
	{
		return (parent->right);
	}
	else if (parent->right->right == node || parent->right->left == node)
	{
		return (parent->left);
	}
	return (NULL);
}
