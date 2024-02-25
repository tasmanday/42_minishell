/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:43:17 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 12:20:37 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Setup FDs for the simple command.
 * 
 * Does this to allow pipes to chain the FDs together.
 * 
 * @param cmd The command.
 * @return int 0 if success. Other value if error.
 */
int	setup_fds(t_command *cmd)
{
	int	ret;

	ret = dup2(cmd->fd_in, STDIN_FILENO);
	if (ret == -1)
	{
		print_err("msh_internal: could not setup stdin dup\n");
		return (-1);
	}
	ret = dup2(cmd->fd_out, STDOUT_FILENO);
	if (ret == -1)
	{
		print_err("msh_internal: could not setup stdout dup\n");
		return (-1);
	}
	return (0);
}

/**
 * @brief Set the up fds and backs up the original values.
 * 
 * Setups up the FDs for the command and backs up the originals. Does this
 * because the builtins are not run in a child process.
 * 
 * @param cmd The command.
 * @param backup_fd_stdin The location to backup the stdin FD.
 * @param backup_fd_stdout The location to backup the stdout FD.
 * @return int 0 if success. Other value if error.
 */
int	setup_fds_and_backup(t_command *cmd, int *bup_fd_stdin, int *bup_fd_stdout)
{
	int	ret;

	*bup_fd_stdin = dup(STDIN_FILENO);
	*bup_fd_stdout = dup(STDOUT_FILENO);
	ret = setup_fds(cmd);
	return (ret);
}

/**
 * @brief Restores the FDs to the backed up values.
 * 
 * @param backup_fd_stdin Backed up stdin FD.
 * @param backup_fd_stdout Backed up stdout FD.
 * @return int 0 if success. Other value if error.
 */
int	revert_fds(int backup_fd_stdin, int backup_fd_stdout)
{
	int	ret;

	ret = dup2(backup_fd_stdin, STDIN_FILENO);
	if (ret == -1)
	{
		print_err("msh_internal: could not revert stdin\n");
		return (-1);
	}
	close(backup_fd_stdin);
	ret = dup2(backup_fd_stdout, STDOUT_FILENO);
	if (ret == -1)
	{
		print_err("msh_internal: could not revert stdout\n");
		return (-1);
	}
	close(backup_fd_stdout);
	return (0);
}

/**
 * @brief Tries to execute a builtin function
 * 
 * Searches for a builtin matching the first arg of command. If it does not find
 * it it returns 0 (failure).
 * 
 * If it finds it, it does setup, runs this command, then cleans up before
 * returning with the return value from the command.
 * 
 * @param cmd The command to be run (with it's args, redirections, etc).
 * @param envp The envp (for expansion).
 * @param ret The return value (to update the return value if successful run).
 * @param last_exit The last exit (for expansion).
 * @return int True (1) if ran successfully. False (0) if failed to run.
 */
int	try_execute_builtin(t_command *cmd, char ***envp, int *ret, int last_exit)
{
	char	*builtin_path_str;
	char	**args;
	int		backup_fd_stdin;
	int		backup_fd_stdout;

	*ret = 0;
	if (!cmd->args)
		return (0);
	builtin_path_str = builtin_command_search(cmd->args->content);
	if (builtin_path_str == NULL)
		return (0);
	*ret = setup_fds_and_backup(cmd, &backup_fd_stdin, &backup_fd_stdout);
	if (*ret == -1)
		return (free(builtin_path_str), 0);
	*ret = handle_redirections(cmd->redirections, *envp, last_exit);
	if (*ret != 0)
		return (free(builtin_path_str), 0);
	args = linked_list_to_char_array(cmd->args);
	if (!args)
		return (free(builtin_path_str), 0);
	*ret = builtin_execve(builtin_path_str, args, envp);
	free(builtin_path_str);
	free_char_array(args);
	revert_fds(backup_fd_stdin, backup_fd_stdout);
	return (1);
}

/**
 * @brief AST node traversal. For execution of a command type node.
 * 
 * Runs command node from AST tree.
 * 
 * Parses tokens in node into a command. Then runs that command and cleans up.
 * 
 * @param node The AST node.
 * @param envp The environment (for expansion).
 * @param last_exit Last exit value (for expansion).
 * @return int The return value from the command execution.
 */
int	do_command(t_ast_node *node, char ***envp, int last_exit)
{
	int			ret;
	t_command	*cmd;

	cmd = new_cmd_from_tokens(&node->tokens, *envp, last_exit);
	if (!cmd)
	{
		print_err("msh_internal: failed to malloc/make command. Bug?\n");
		delete_ast_tree(node);
		return (1);
	}
	cmd->fd_in = node->fd_in;
	cmd->fd_out = node->fd_out;
	delete_ast_tree(node);
	ret = 0;
	if (cmd->args && is_builtin(cmd->args->content))
		try_execute_builtin(cmd, envp, &ret, last_exit);
	else
		try_execute_command(cmd, envp, &ret, last_exit);
	delete_command(cmd);
	return (ret);
}
