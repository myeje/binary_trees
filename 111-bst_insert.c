#include "binary_trees.h"
/**
 * bst_insert - Insert a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *curr;

	if (!tree)
		return (NULL);

	new_node = malloc(sizeof(bst_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	curr = *tree;
	while (curr != NULL)
	{
		if (value < curr->n)
		{
			if (curr->left == NULL)
			{
				curr->left = new_node;
				new_node->parent = curr;
				break;
			}
			curr = curr->left;
		}
		else if (value > curr->n)
		{
			if (curr->right == NULL)
			{
				curr->right = new_node;
				new_node->parent = curr;
				break;
			}
			curr = curr->right;
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	return (new_node);
}
