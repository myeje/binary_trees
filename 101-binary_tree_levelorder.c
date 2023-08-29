#include "binary_trees.h"

/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: no return(void).
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *pop[1024];
	size_t m = 0, i = 0;
	binary_tree_t *current;

	if (!tree || !func)
	       return;

	pop[i++] = (binary_tree_t *) tree;

	while (m < i)
	{
		current = pop[m++];
		func(current->n);

		if (current->left != NULL)
			pop[i++] = current->left;

		if (current->right != NULL)
			pop[i++] = current->right;
	}
}
