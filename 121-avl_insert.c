#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree for inserting.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *pop = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursion(tree, *tree, &pop, value);
	return (pop);
}

/**
 * avl_insert_recursion - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of AVL tree.
 * @pat: The parent node.
 * @pop: A double pointer.
 * @value: The value to be insert into AVL tree.
 *
 * Return: A pointer to the new root or NULL.
 */
avl_t *avl_insert_recursion(avl_t **tree, avl_t *pat, avl_t **pop, int value)
{
	int b;

	if (*tree == NULL)
		return (*pop = binary_tree_node(pat, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursion(&(*tree)->left, *tree, pop, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursion(&(*tree)->right, *tree, pop, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b = avi_balance_factor(*tree);
	if (b > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avi_balance_factor - Calculate the balance factor of an AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Balance factor.
 */
int avi_balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * height - Calculate the height of a binary tree
 * @tree: A pointer to the root node of the tree.
 *
 * Return: height.
 */
size_t height(const binary_tree_t *tree)
{
	size_t pop = 0, lop = 0;

	if (tree != NULL)
	{
		pop = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		lop = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((pop > lop) ? pop : lop);
	}
	return (0);
}
