#include "binary_trees.h"

/**
 * max - Return the maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 * Return: The maximum value between @a and @b.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * binary_height - Compute the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The height of the tree.
 */
int binary_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_height(tree->left);
	right_height = binary_height(tree->right);

	return (1 + max(left_height, right_height));
}

/**
 * binary_tree_is_avl_recursive - Check if a binary tree is an AVL.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value allowed in the tree.
 * @max: Maximum value allowed in the tree.
 * Return: 1 if @tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl_recursive(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = binary_height(tree->left);
	right_height = binary_height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return ((binary_tree_is_avl_recursive(tree->left, min, tree->n - 1) &&
		 binary_tree_is_avl_recursive(tree->right, tree->n + 1, max)));
}

/**
 * binary_tree_is_avl - Check if a binary tree is an AVL tree.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if @tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((binary_tree_is_avl_recursive(tree, INT_MIN, INT_MAX)));
}
