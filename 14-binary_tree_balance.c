#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	int left = binary_tree_height(tree->left);
	int right = binary_tree_height(tree->right);

	return (left - right);
}
