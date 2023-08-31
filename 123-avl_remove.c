#include "binary_trees.h"

/**
 * avl_balance - Balances an AVL tree after insertions or deletions.
 * @node: A pointer to the root node of the tree.
 *
 * Return: A pointer to the new root node after balancing
 */
avl_t *avl_balance(avl_t *node)
{
    int balance_factor = binary_tree_balance(node);

    if (balance_factor > 1) {
        if (binary_tree_balance(node->left) >= 0)
            return (binary_tree_rotate_right(node));
        else {
            node->left = binary_tree_rotate_left(node->left);
            return (binary_tree_rotate_right(node));
        }
    }

    if (balance_factor < -1) {
        if (binary_tree_balance(node->right) <= 0)
            return (binary_tree_rotate_left(node));
        else {
            node->right = binary_tree_rotate_right(node->right);
            return (binary_tree_rotate_left(node));
        }
    }

    return (node);
}

/**
 * avl_remove - this function removes a node from an AVL tree
 * @root: pointer to the root node of tree to remove
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *sub = NULL;

	if (!root)
	{
		return (NULL);
	}

	if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
	}
	else if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
	}
	else
	{
		if (!root->right || !root->left)
		{
			sub = root->left ? root->left : root->right;
			free(root);
			return sub;
		}
		sub = root->right;
		while (sub->left)
		{
			sub = sub->left;
		}
		root->n = sub->n;
		root->right = avl_remove(root->right, sub->n);
	}

	root = avl_balance(root);
	return (root);
}
