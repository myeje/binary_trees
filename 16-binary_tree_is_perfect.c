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

	if (!tree->left && !tree->right)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_count - counts number of nodes
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 or the height.
*/
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_count(tree->left) + binary_tree_count(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t actual;
	size_t outcome;

	if (!tree)
	{
		return (0);
	}

	height = binary_tree_height(tree);
	outcome = pow((2, height) - 1);
	actual = binary_tree_count(tree);

	return (actual == outcome);
}
