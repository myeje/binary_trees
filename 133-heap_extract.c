#include "binary_trees.h"

/**
 * heap_extract - this function gets number of nodes in a heap
 * @root: A pointer to the root node
 *
 * Return: return 0 or the number of heap nodes.
*/
size_t heap_count(heap_t *root) {
    if (root == NULL) {
        return 0;
    }

    return (1 + heap_count(root->left) + heap_count(root->right));
}

/**
 * heap_extract - this function swaps 2 heap nodes
 * @a: first heap node
 * @b: second heap node
*/
void heap_swap(heap_t *a, heap_t *b) {
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_down - this function heapify the heap
 * @root: A pointer to the root node
*/
void heapify_down(heap_t *root) {
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n) {
        largest = left;
    }

    if (right && right->n > largest->n) {
        largest = right;
    }

    if (largest != root) {
        heap_swap(root, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - this function extracts root node
 * @root: A pointer to the root node
 *
 * Return: return 0 or the extracted value.
*/
int heap_extract(heap_t **root) {
    if (*root == NULL) {
        return (0);
    }

    int extracted_value = (*root)->n;
    size_t node_count = heap_count(*root);
    heap_t *last_node = heap_nth_node(*root, node_count);

    heap_swap(*root, last_node);
    if (last_node->parent && last_node->parent->right == last_node) {
        last_node->parent->right = NULL;
    } else if (last_node->parent && last_node->parent->left == last_node) {
        last_node->parent->left = NULL;
    }

    free(last_node);

    if (*root) {
        heapify_down(*root);
    }

    return (extracted_value);
}
