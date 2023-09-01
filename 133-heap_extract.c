#include "binary_trees.h"

/**
 * sum_height - Calculate heights of a binary tree
 * @tree: pointer to the root node of the tree.
 *
 * Return: Lenght of height or 0 if NULL.
 */
size_t sum_height(const binary_tree_t *tree)
{
	size_t size = 0;
	size_t size2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		size = 1 + sum_height(tree->left);

	if (tree->right)
		size2 = 1 + sum_height(tree->right);

	if (size > size2)
		return (size);
	return (size2);
}

/**
 * Extract - Using pre-order to traversal.
 * @tree: pointer to the root node of the tree.
 * @pop: double pointer
 * @size: size of tree
 *
 * Return: No Return
 */
void extract(heap_t *tree, heap_t **pop, size_t size)
{
	if (!tree)
		return;

	if (!size)
		*pop = tree;
	size--;

	extract(tree->left, pop, size));
	extract(tree->right, pop, size);
}

/**
 * heapify - Heapifies max binary heap.
 * @root: pointer to binary heap of binary tree.
 *
 * Return: no return.
 */
void heapify(heap_t *root)
{
	heap_t *tmp, *b;
	int val;

	if (!root)
		return;

	tmp = root;

	while (1)
	{
		if (!tmp->left)
			break;
		if (!tmp->right)
			b = tmp->left;
		else
		{
			if (tmp->left->n > tmp->right->n)
				b = tmp->left;
			else
				b = tmp->right;
		}
		if (tmp->n > b->n)
			break;
		val = tmp->n;
		tmp->n = b->n;
		b->n = val;
		tmp = b;
	}
}

/**
 * heap_extract - Extracts root node from a Max Binary Heap
 * @root: pointer to the heap root of the tree.
 *
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int val;
	heap_t *pop, *tree;

	if (!root || !*root)
		return (0);
	pop = *root;
	val = pop->n;
	if (!pop->left && !pop->right)
	{
		*root = NULL;
		free(pop);
		return (val);
	}

	extract(pop, &tree, sum_height(pop));

	pop->n = tree->n;
	if (tree->parent->right)
		tree->parent->right = NULL;
	else
		tree->parent->left = NULL;
	free(tree);
	heapify(pop);
	*root = pop;
	return (val);
}
