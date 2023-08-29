#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left != NULL || tree->right != NULL)
	{
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
	}
	else
	{
		return (0);	
	}
}
