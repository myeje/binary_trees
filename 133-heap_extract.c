#include "binary_trees.h"

/**
 * max_count - Calculates the max of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: max of the binary tree.
 */
heap_t *max_count(heap_t *tree)
{
	heap_t *pop, *lop, *pol;

	if (!tree->left)
		return (tree);
	lop = max_count(tree->left);
	if (lop->n > tree->n)
		pop = lop;
	else
		pop = tree;
	if (tree->right)
	{
		pol = max_count(tree->right);
		if (pol->n > pop->n)
			pop = pol;
		else
			pop = tree;
	}
	return (pop);
}

/**
 * extract_recur - extract max from binary tree.
 * @tree:Pointer to the root node of the binary tree.
 *
 * Return: no return(void)
 */
void extract_recur(heap_t *tree)
{
	heap_t *pop, *lop = NULL;

	if (!tree->left)
		return;
	pop = max_count((tree)->left);
	if (!tree->right)
		lop = max_count(tree->right);
	if (lop && lop->n > pop->n)
		pop = lop;
	tree->n = pop->n;
	if (!pop->left)
	{
		if (pop->parent && pop->parent->left == pop)
			pop->parent->left = NULL;
		if (pop->parent && pop->parent->right == pop)
			pop->parent->right = NULL;
		free(pop);
	}
	else
		extract_recur(pop);
}

/**
 * heap_extract - Extract root node of Max binary heap.
 * @root: A doubly pointer to the root node.
 *
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int pop;

	if (!*root)
		return (0);

	pop = (*root)->n;
	if (!(*root)->left)
	{
		pop = (*root)->n;
		free(*root);
		*root = NULL;
		return (pop);
	}
	extract_recur(*root);
	return (pop);
}
