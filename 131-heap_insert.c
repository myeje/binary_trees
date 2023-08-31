#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value to the
 * max binary heap
 * @root: double pointer to the root node of the heap to insert to
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node or Null on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	int sub, tmp, lvl, bit, leave, size;
	heap_t *temp, *tree, *swap;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leave = size;
	for (lvl = 0, sub = 1; leave >= sub; sub *= 2, lvl++)
	{
		leave -= sub;
	}

	for (bit = 1 << (lvl - 1); bit != 1; bit >>= 1)
	{
		tree = leave & bit ? tree->right : tree->left;
	}

	temp = binary_tree_node(tree, value);
	leave & 1 ? (tree->right = temp) : (tree->left = temp);

	swap = temp;
	for (; swap->parent && (swap->n > swap->parent->n); swap = swap->parent)
	{
		tmp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = tmp;
		temp = temp->parent;
	}

	return (temp);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 or depth.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
