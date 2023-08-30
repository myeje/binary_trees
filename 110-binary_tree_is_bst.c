#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: 0 or 1.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int pop = -1;

	if (tree == NULL)
		return (0);

	return (binary_tree_recursive(tree, &pop));
}

/**
 * binary_tree_recursive - Helper function for recursion.
 * @tree: pointer to the root node.
 * @pop: pointer to the previous visited node.
 *
 * Return: 1 or 0.
 */
int binary_tree_recursive(const binary_tree_t *tree, int *pop)
{
	if (tree == NULL)
		return (1);

	if (!binary_tree_recursive(tree->left, pop))
		return (0);

	if (*pop != -1 && tree->n <= *pop)
		return (0);

	*pop = tree->n;

	if (!binary_tree_recursive(tree->right, pop))
		return (0);

	return (1);
}
