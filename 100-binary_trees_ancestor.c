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
	size_t i, m;
	size_t l, u;

	if (!first || !second)
	{
		return (NULL);
	}

	while (first)
	{
		first_path[i++] = (binary_tree_t *)first;
		first = first->parent;
	}

	while (second)
	{
		second_path[m++] = (binary_tree_t *)second;
		second = second->parent;
	}

	l = i - 1, u = m - 1;

	while (l > 0 && u >0 &&first_path[l - 1] == second_path[u - 1])
	{
		l--;
		u--;
	}

	if (l == 0 || u == 0)
	{
		return (NULL);
	}

	return (binary_tree_t *)first_path[l - 1];
}
