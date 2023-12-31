#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second .
 *
 * Return: a pointer to the lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *first_path[MAX_PATH];
	binary_tree_t *second_path[MAX_PATH];
	size_t i, m;

	if (!first || !second)
	{
		return (NULL);
	}

	for (i = 0; first; i++)
	{
		first_path[i] = (binary_tree_t *)first;
		first = first->parent;
	}

	for (m = 0; second; m++)
	{
		second_path[m] = (binary_tree_t *)second;
		second = second->parent;
	}

	if (!i || !m)
	{
		return (NULL);
	}

	if (first_path[i - 1] != second_path[m - 1])
	{
		return (NULL);
	}

	while (i > 0 && m > 0 && first_path[i - 1] == second_path[m - 1])
	{
		i--;
		m--;
	}

	return (first_path[i]);
}
