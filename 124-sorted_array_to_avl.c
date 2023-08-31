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
	if (!array || size == 0)
	{
		return (NULL);
	}
	
	return (build_avl(array, 0, size - 1));
}

/**
 * build_avl - function to build an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @start: start of the current subtree
 * @end: end of the current subtree.
 *
 * Return: pointer to the root node of the subtree
 */
avl_t *build_avl(int *array, int start, int end)
{
	if (start > end)
	{
		return (NULL);
	}
	
	int mid = (start + end) / 2;
	avl_t *root = binary_tree_node(NULL, array[mid]);
	
	if (!root)
	{
		return (NULL);
	}
	
	root->left = build_avl(array, start, mid - 1);
	root->right = build_avl(array, mid + 1, end);
	
	return (root);
}
