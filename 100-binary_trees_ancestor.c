#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: a pointer to the lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_path[1024];
	binary_tree_t *second_path[1024];
	int i, m;

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

	while (i > 0 && m > 0 && first_path[i - 1] == second_path[m - 1])
	{
		i--;
		m--;
	}

	return (first_path[i - 1]);
}
