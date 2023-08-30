#include "binary_trees.h"

/**
 * bst_remove - Remove a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *temp, *node;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		node = bst_minimum(root->right);
		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
	}

	return (root);
}

/**
 * bst_minimum - Find the minimum node in a BST.
 * @tree: Pointer to the root node of the BST.
 * Return: Pointer to the minimum node.
 */
bst_t *bst_minimum(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;

	return (tree);
}
