#include "binary_trees.h"

/**
 * bst_remove - Remove a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursion(root, root, value));
}

/**
 * bst_remove_recursion - Helper function taht removes binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @ptr: A pointer to the current node in the BST..
 * @value: The value to remove.
 *
 * Reture: a pointer to the root node.
 */
bst_t *bst_remove_recursion(bst_t *root, bst_t *ptr, int value)
{
	if (ptr != NULL)
	{
		if(ptr->n == value)
			return (bst_del(root, ptr));
		if (ptr->n > value)
			return (bst_remove_recursion(root, ptr->left, value));
		return (bst_remove_recursion(root, ptr->right, value));
	}
	return (NULL);
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


/**
 * bst_del - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @ptr: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node.
 */
bst_t *bst_del(bst_t *root, bst_t *ptr)
{
	bst_t *parent, *pop = NULL;
       
	parent = ptr->parent;

	if (ptr->left == NULL)
	{
		if (parent != NULL && parent->left == ptr)
			parent->left = ptr->right;
		else if (parent != NULL)
			parent->right = ptr->right;
		if (ptr->right != NULL)
			ptr->right->parent = parent;
		free(ptr);
		return (parent == NULL ? ptr->right : root);
	}

	if (ptr->right == NULL)
	{
		if (parent != NULL && parent->left == ptr)
			parent->left = ptr->left;
		else if (parent != NULL)
			parent->right = ptr->left;
		if (ptr->left != NULL)
			ptr->left->parent = parent;
		free(ptr);
		return (parent == NULL ? ptr->left : root);
	}

	pop = bst_minimum(ptr->right);
	ptr->n = pop->n;

	return (bst_del(root, pop));
}
