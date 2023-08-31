#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: amount of elements in the array
 *
 * Return: pointer to the root node of the AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *sub = NULL;

	if (!array || size == 0)
	{
		return (NULL);
	}

	mid = (size - 1) / 2;
	sub = binary_tree_node(NULL, array[mid]);
	build_avl(&sub, array, -1, mid);
	build_avl(&sub, array, mid, size);

	return (sub);
}

/**
 * build_avl - function to build an AVL tree from a sorted array
 * @root: double pointer to root node of subtree
 * @array: pointer to the first element of the array
 * @start: start of the current subtree
 * @end: end of the current subtree.
 */
void build_avl(avl_t **root, int *array, size_t start, size_t end)
{
	avl_t *temp = NULL;
	size_t mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		temp = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = temp;
		else if (array[mid] < (*root)->n)
			(*root)->left = temp;
		build_avl(&temp, array, start, mid);
		build_avl(&temp, array, mid, end);
	}
}
