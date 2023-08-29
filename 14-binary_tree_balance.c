#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
		return (0);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
