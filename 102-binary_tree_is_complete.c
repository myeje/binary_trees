#include "binary_trees.h"

/**
 * binary_tree_is_complete -  checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = 0, rear = 0, null_seen = 0;
	binary_tree_t *current, **queue;

	if (tree == NULL)
		return 0;

	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return 0;


	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
		{
			null_seen = 1;
		}
		else
		{
			if (null_seen)
			{
				free(queue);
				return 0;
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	free(queue);
	return 1;

}
