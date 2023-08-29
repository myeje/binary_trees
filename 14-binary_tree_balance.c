#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 or the height.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height2;
	int right_height2;

	if (!tree)
	{
		return (0);
	}

	left_height2 = binary_tree_height(tree->left);
	right_height2 = binary_tree_height(tree->right);

	return (left_height2 - right_height2);
}
