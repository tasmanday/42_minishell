/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:06:18 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 13:44:38 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief AST node traversal. For execution of an and type node.
 * 
 * Does the left side. Then does the right side if the left side executed
 * successfully (returned with return value of 0).
 * 
 * @param node The AST node.
 * @param envp The environment (for expansion).
 * @param last_exit The last exit (for expansion).
 * @return int The bubbled up return value from the last side to run.
 */
int	do_and(t_ast_node *node, char ***envp, int last_exit)
{
	int	ret;

	ret = do_ast_node(node->left, envp, last_exit);
	node->left = NULL;
	if (ret > 128)
	{
		delete_ast_tree(node);
		return (ret);
	}
	if (ret != 0)
	{
		delete_ast_tree(node);
		return (ret);
	}
	last_exit = ret;
	ret = do_ast_node(node->right, envp, last_exit);
	node->right = NULL;
	delete_ast_tree(node);
	return (ret);
}

/**
 * @brief AST node traversal. For execution of an or type node.
 * 
 * Does the left side. Then does the right side if the left side executed and
 * exited unsuccessfully (returned with return value != 0)
 * 
 * @param node The AST node.
 * @param envp The environment (for expansion).
 * @param last_exit The last exit (for expansion).
 * @return int The bubbled up return value from the last side to run.
 */
int	do_or(t_ast_node *node, char ***envp, int last_exit)
{
	int	ret;

	ret = do_ast_node(node->left, envp, last_exit);
	node->left = NULL;
	if (ret > 128)
	{
		delete_ast_tree(node);
		return (ret);
	}
	if (ret == 0)
	{
		delete_ast_tree(node);
		return (ret);
	}
	last_exit = ret;
	ret = do_ast_node(node->right, envp, last_exit);
	node->right = NULL;
	delete_ast_tree(node);
	return (ret);
}

/*
*	@brief: Norm helper for do_brackets
*/
int	do_brackets_child(t_ast_node *node, char ***envp, int last_exit, int *ret)
{
	t_list	*redirections;

	sig_initialiser_do_nothing();
	redirections = tokens_to_redirection_list(&node->tokens);
	ft_deque_destroy_list(&node->tokens, delete_token_node_void);
	*ret = handle_redirections(redirections, *envp, last_exit);
	if (*ret != 0)
	{
		delete_ast_tree(node);
		exit(*ret);
	}
	*ret = do_ast_node(node->left, envp, 0);
	node->left = NULL;
	delete_ast_tree(node);
	ft_lstclear(&redirections, delete_redirection_void);
	exit(*ret);
}

/**
 * @brief AST node traversal. For exection of a bracket type node.
 * 
 * Sets up subshell for brackets to run inside.
 * 
 * Parses the tokens into redirections and sets up these redirections if they
 * exist.
 * 
 * Eg: for (foo && bar) > out.txt
 * 
 * Sets up the out.txt redirection.
 * 
 * Recursively calls do_ast_node on the child nodes.
 * 
 * @param node The AST node.
 * @param envp The environment (for expansions).
 * @param last_exit The last exit (for expansions).
 * @return int The bubbled up return value of the child node.
 */
int	do_brackets(t_ast_node *node, char ***envp, int last_exit)
{
	int		ret;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (delete_ast_tree(node), 1);
	if (pid == 0)
	{
		do_brackets_child(node, envp, last_exit, &ret);
	}
	waitpid(pid, &ret, 0);
	delete_ast_tree(node);
	return (WEXITSTATUS(ret));
}
