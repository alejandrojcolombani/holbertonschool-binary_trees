#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* node with only one child */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* node with two children */
	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}
