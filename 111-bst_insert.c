#include "binary_trees.h"

/**
 * create_bst_node - Create a new Binary Search Tree node.
 * @value: The value to store in the node.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *create_bst_node(int value)
{
	bst_t *new_node = malloc(sizeof(bst_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * bst_insert_recursive - Insert a value into a Binary Search Tree recursively.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert_recursive(bst_t **tree, int value)
{
	bst_t *curr;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = create_bst_node(value);
		return (*tree);
	}

	curr = *tree;
	if (value < curr->n)
	{
		if (curr->left == NULL)
		{
			curr->left = create_bst_node(value);
			if (curr->left)
				curr->left->parent = curr;
			return (curr->left);
		}
		return (bst_insert_recursive(&(curr->left), value));
	}
	else if (value > curr->n)
	{
		if (curr->right == NULL)
		{
			curr->right = create_bst_node(value);
			if (curr->right)
				curr->right->parent = curr;
			return (curr->right);
		}
		return (bst_insert_recursive(&(curr->right), value));
	}
	return (NULL);
}

/**
 * bst_insert - Insert a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	return (bst_insert_recursive(tree, value));
}
