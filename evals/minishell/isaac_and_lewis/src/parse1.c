/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:46:33 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 22:54:09 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/**
 * @brief Creates a new empty ast_node allocated on the heap.
 *
 * Allocates a ast_node on the heap and sets all its intial values to "null"
 * values.
 *
 * @return A heap allocated ast_node.
 */
t_ast_node	*new_ast_node(void)
{
	t_ast_node	*ast_node;

	ast_node = malloc(sizeof(t_ast_node) * 1);
	if (!ast_node)
	{
		return (NULL);
	}
	ast_node->type = AST_NONE;
	ast_node->fd_in = 0;
	ast_node->fd_out = 1;
	ast_node->tokens = ft_deque_new();
	ast_node->left = NULL;
	ast_node->right = NULL;
	return (ast_node);
}

/**
 * @brief Deletes a heap allocated ast_node.
 *
 * Frees the contents of an ast_node then the ast_node itself.
 *
 * @param node The ast_node to be deleted.
 */
void	delete_ast_node(t_ast_node *node)
{
	if (!node)
	{
		return ;
	}
	ft_deque_destroy_list(&node->tokens, delete_token_node_void);
	free(node);
	return ;
}

/**
 * @brief Applies function on an AST tree with preorder traversal.
 * 
 * @param node The head node.
 * @param f The function to be applied.
 */
void	ast_node_preorder_apply(t_ast_node *node, void (*f)(t_ast_node *))
{
	if (!node)
	{
		return ;
	}
	f(node);
	if (node->left)
	{
		ast_node_preorder_apply(node->left, f);
	}
	if (node->right)
	{
		ast_node_preorder_apply(node->right, f);
	}
}

/**
 * @brief Applies function on an AST tree with postorder traversal.
 * 
 * @param node The head node.
 * @param f The funtion to be applied.
 */
void	ast_node_postorder_apply(t_ast_node *node, void (*f)(t_ast_node *))
{
	if (!node)
	{
		return ;
	}
	if (node->left)
	{
		ast_node_postorder_apply(node->left, f);
	}
	if (node->right)
	{
		ast_node_postorder_apply(node->right, f);
	}
	f(node);
}

/**
 * @brief Deletes an AST tree.
 * 
 * @param head The head of the AST tree.
*/
void	delete_ast_tree(t_ast_node *head)
{
	ast_node_postorder_apply(head, delete_ast_node);
}
