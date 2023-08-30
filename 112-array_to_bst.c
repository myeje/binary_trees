#include "binary_trees.h"

/**
 * array_bst_recursive - Helper function for recursive array to BST conversion.
 * @array: Pointer to the array to be converted.
 * @start: Index of the start element in the array.
 * @end: Index of the end element in the array.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_bst_recursive(int *array, size_t start, size_t end)
{
	bst_t * root;
	size_t middle;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	root = (NULL);

	if (array[middle] != 0)
	{
		root = bst_insert(&root, array[middle]);

		if (root == NULL)
			return (NULL);

		root->left = array_bst_recursive(array, start, middle - 1);
		if (root->left != NULL)
			root->left->parent = root;

		root->right = array_bst_recursive(array, middle + 1, end);
		if (root->right != NULL)
			root->right->parent = root;
	}
	return (root);
}

/**
 * array_to_bst - Build a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

    return (array_bst_recursive(array, 0, size - 1));
}

