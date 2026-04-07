#include "binary_trees.h"

/**
 * tree_height - measures height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height of tree, -1 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
