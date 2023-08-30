#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: A pointer to the node.
 *
 * Return: NULL or uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;
	
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
    }
	
	grandparent = node->parent->parent;
	if (grandparent->left == node->parent)
	{
		return grandparent->right;
	}
	else if (grandparent->right == node->parent)
	{
		return grandparent->left;
	}
	
	return (NULL);
}
