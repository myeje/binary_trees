#include "binary_trees.h"

/**
 * array_to_avl - this function builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: amount of elements in the array
 *
 * Return: pointer to the root node of the AVL tree, or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t a;

    if (!array)
	{
		return (NULL);
	}

	for (a = 0; a < size; a++)
	{
		avl_insert(&root, array[a]);
	}

	return (root);
}
