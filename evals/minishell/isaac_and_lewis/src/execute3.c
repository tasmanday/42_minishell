/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:08:14 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/14 12:03:09 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	do_pipe_left_child(t_ast_node *node, int pipe_fd[2], char ***envp,
	int last_exit)
{
	t_ast_node	*left;
	int			ret;

	sig_initialiser_do_nothing();
	node->left->fd_out = pipe_fd[1];
	close(pipe_fd[0]);
	left = node->left;
	node->left = NULL;
	delete_ast_tree(node);
	ret = do_ast_node(left, envp, last_exit);
	exit(ret);
}

void	do_pipe_right_child(t_ast_node *node, int pipe_fd[2], char ***envp,
	int last_exit)
{
	t_ast_node	*right;
	int			ret;

	sig_initialiser_do_nothing();
	node->right->fd_in = pipe_fd[0];
	right = node->right;
	node->right = NULL;
	delete_ast_tree(node);
	ret = do_ast_node(right, envp, last_exit);
	exit(ret);
}

/**
 * @brief AST node traversal. For execution of a pipe type node.
 * 
 * Sets up a pipe and a fork for either side. Then in each side, runs that side
 * of the tree with the output from the left piped into the input of the right.
 * 
 * Waits for these to finish then returns with the exit value of the right side.
 * 
 * @param node The AST node.
 * @param envp The environment (for expansion).
 * @param last_exit The last exit value (for expansion).
 * @return int The bubbled up exit value from the right side.
 */
int	do_pipe(t_ast_node *node, char ***envp, int last_exit)
{
	int			pipe_fd[2];
	int			ret;
	pid_t		pid0;
	pid_t		pid1;

	ret = pipe(pipe_fd);
	if (ret < 0)
		return (delete_ast_tree(node), 1);
	pid0 = fork();
	if (pid0 < 0)
		return (delete_ast_tree(node), 1);
	if (pid0 == 0)
		do_pipe_left_child(node, pipe_fd, envp, last_exit);
	close(pipe_fd[1]);
	pid1 = fork();
	if (pid1 < 0)
		return (delete_ast_tree(node), 1);
	if (pid1 == 0)
		do_pipe_right_child(node, pipe_fd, envp, last_exit);
	waitpid(pid0, &ret, 0);
	close(pipe_fd[0]);
	waitpid(pid1, &ret, 0);
	delete_ast_tree(node);
	return (WEXITSTATUS(ret));
}

/**
 * @brief AST node traversal/execution. For recursive execution of AST.
 * 
 * Called on head node. Then calles subroutine based on the type of that node.
 * Through recursive calls will traverse entire tree in correct order.
 * 
 * @param node The head of the AST tree.
 * @param envp The environment (for expansion).
 * @param last_exit The last exit (for expansion).
 * @return int The bubbled up return value from the execution of the tree.
 */
int	do_ast_node(t_ast_node *node, char ***envp, int last_exit)
{
	if (!node)
		return (last_exit);
	if (node->type == AST_CMD)
		return (do_command(node, envp, last_exit));
	if (node->left == NULL)
		return (1);
	node->left->fd_in = node->fd_in;
	node->left->fd_out = node->fd_out;
	if (node->type == AST_BRACKETS)
		return (do_brackets(node, envp, last_exit));
	if (node->right == NULL)
		return (1);
	node->right->fd_in = node->fd_in;
	node->right->fd_out = node->fd_out;
	if (node->type == AST_PIPE)
		return (do_pipe(node, envp, last_exit));
	if (node->type == AST_AND)
		return (do_and(node, envp, last_exit));
	if (node->type == AST_OR)
		return (do_or(node, envp, last_exit));
	return (1);
}
