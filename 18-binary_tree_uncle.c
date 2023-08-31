#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: A pointer to the node.
 *
 * Return: NULL or uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *gran;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	gran = node->parent->parent;
	if (gran->left->left == node->parent)
	{
		return (gran->right);
	}
	else
	{
		return (gran->left);
	}
}
