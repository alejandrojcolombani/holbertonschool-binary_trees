#include "binary_trees.h"

/**
 * tree_depth - measures the depth of the leftmost leaf
 * @tree: pointer to the root node
 *
 * Return: depth
 */
size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree->left != NULL)
	{
		tree = tree->left;
		depth++;
	}

	return (depth);
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * @depth: expected leaf depth
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = tree_depth(tree);
	return (is_perfect(tree, depth, 0));
}
