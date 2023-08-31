#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    if (!binary_tree_is_complete(tree))
        return 0;

    if (!binary_tree_has_max_heap_property(tree))
        return 0;

    return 1;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return 1;

    if (!binary_tree_is_complete(tree->left))
        return 0;

    if (!binary_tree_is_complete(tree->right))
        return 0;

    return (binary_tree_height(tree->left) == binary_tree_height(tree->right));
}

/**
 * binary_tree_has_max_heap_property - Checks if a binary tree has max heap property.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree has max heap property, 0 otherwise.
 */
int binary_tree_has_max_heap_property(const binary_tree_t *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->left->n > tree->n)
        return 0;

    if (tree->right && tree->right->n > tree->n)
        return 0;

    return (binary_tree_has_max_heap_property(tree->left) &&
            binary_tree_has_max_heap_property(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}
