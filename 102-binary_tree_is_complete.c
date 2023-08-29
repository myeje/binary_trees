#include "binary_trees.h"

/**
 * binary_tree_is_complete -  checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i = 0, m = 0, j;
	binary_tree_t *pop[MAX_PATH];
	binary_tree_t *current;

	if (!tree)
	{
		return (0);
	}

	pop[i++] = (binary_tree_t *) tree;

	while (m < i)
	{
		current = pop[m++];

		if (current->left != NULL)
			pop[i++] = current->left;

		if (current->right != NULL)
			pop[i++] = current->right;

		if (!current->left && current->right)
		{
			return (0);
		}
		if ((current->left || current->right) && pop[m] == NULL)
		{
			for (j = m; j < i; j++)
			{
				if (pop[j] != NULL)
				{
					return (0);
				}
			}
		}
	}
	return (1);
}

