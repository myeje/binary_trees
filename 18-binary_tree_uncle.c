#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a binary tree node.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: A pointer to the node.
 *
 * Return: NULL or uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}
