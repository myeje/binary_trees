#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
