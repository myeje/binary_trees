#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the new node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (!root)
        return NULL;

    heap_t *new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root) {
        *root = new_node;
        return new_node;
    }

    heap_t *parent = find_insertion_parent(*root);
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    heapify_up(new_node);

    return new_node;
}

/**
 * find_insertion_parent - Finds the parent node for insertion in Max Heap.
 * @root: A pointer to the root node of the Heap.
 *
 * Return: A pointer to the parent node.
 */
heap_t *find_insertion_parent(heap_t *root)
{
    if (!root)
        return NULL;

    if (!root->left || !root->right)
        return root;

    if (binary_tree_size(root->left) <= binary_tree_size(root->right))
        return find_insertion_parent(root->left);
    else
        return find_insertion_parent(root->right);
}

/**
 * heapify_up - Restores the Max Heap property after insertion.
 * @node: The newly inserted node.
 */
void heapify_up(heap_t *node)
{
    if (!node || !node->parent)
        return;

    if (node->n > node->parent->n) {
        int temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        heapify_up(node->parent);
    }
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    return binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
}
