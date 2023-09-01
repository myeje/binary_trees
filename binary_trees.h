#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#define MAX_PATH 1024

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *avl_balance(avl_t *node);
avl_t *sorted_array_to_avl(int *array, size_t size);
void build_avl(avl_t **root, int *array, size_t start, size_t end);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_validity(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);

/*Print function prototype*/
void binary_tree_print(const binary_tree_t *tree);

/** Helper function **/
int binary_tree_recursive(const binary_tree_t *tree, int *pop);
bst_t *create_bst_node(int value);
bst_t *bst_insert_recursive(bst_t **tree, int value);
bst_t *bst_minimum(bst_t *tree);
bst_t *bst_remove_recursion(bst_t *root, bst_t *ptr, int value);
bst_t *bst_del(bst_t *root, bst_t *ptr);
int max(int a, int b);
int binary_tree_is_avl_recursive(const binary_tree_t *tree, int min, int max);
int binary_height(const binary_tree_t *tree);
size_t avl_height(const avl_t *node);
size_t height(const binary_tree_t *tree);
int avi_balance_factor(const binary_tree_t *tree);
avl_t *avl_insert_recursion(avl_t **tree, avl_t *pat, avl_t **pop, int value);
avl_t *avl_insert(avl_t **tree, int value);
size_t heap_size(heap_t *root);
void heap_swap(heap_t *a, heap_t *b);
void extract_recur(heap_t *tree);
heap_t *max_count(heap_t *tree);
#endif
