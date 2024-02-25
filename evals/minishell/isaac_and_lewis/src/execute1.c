/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:00:07 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 12:56:17 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	delete_and_exit(t_command *cmd, int ret)
{
	delete_command(cmd);
	exit(ret);
}

void	edae(t_command *cmd, int ret, char *str, char *str_arg)
{
	print_err(str, str_arg);
	delete_and_exit(cmd, ret);
}

void	edaef(t_command *cmd, int ret, char *str, char *str_arg)
{
	print_err(str, str_arg);
	free(str_arg);
	delete_and_exit(cmd, ret);
}

void	tec_child(t_command *cmd, char ***envp, int *ret, int last_exit)
{
	char	**args;
	char	*path_str;

	*ret = setup_fds(cmd);
	if (*ret != 0)
		delete_and_exit(cmd, *ret);
	*ret = handle_redirections(cmd->redirections, *envp, last_exit);
	if (*ret != 0)
		delete_and_exit(cmd, *ret);
	if (!cmd->args)
		delete_and_exit(cmd, 0);
	if (ft_strncmp(cmd->args->content, "", 1) == 0)
		edae(cmd, 127, "msh: %s: command not found\n", cmd->args->content);
	path_str = command_search(cmd->args->content, envp);
	if (path_str == NULL)
		edae(cmd, 127, "msh: %s: command not found\n", cmd->args->content);
	if (is_directory(path_str))
		edaef(cmd, 126, "msh: %s: is a directory\n", path_str);
	args = linked_list_to_char_array(cmd->args);
	if (!args)
		fde(cmd, path_str);
	*ret = execve(path_str, args, *envp);
	tecc_norm1(cmd, path_str, args);
	if (errno == 2)
		exit(127);
}

/**
 * @brief Tries to execute a command.
 * 
 * Searches for a binary available to run the first arg of the command. If it
 * does not find it returns 0 for unsuccessful.
 * 
 * If it finds the binary, does setup, forks, runs the binary, waits for the
 * fork to complete then returns with the binary's exit value.
 * 
 * A little different from builtin executeable as it opens the FDs regardless of
 * whether it is successful finding a binary or not.
 * 
 * This allows for the files to be created (and overwritten lol) even if the
 * binary does not exist. This is to match bash behaviour.
 * 
 * @param cmd The command to be run (with it's args, redirections, etc).
 * @param envp The envp (for expansion).
 * @param ret The return value (to update the return value if successful run).
 * @param last_exit The last exit (for expansion).
 * @return int True (1) if ran successfully. False (0) if failed to run.
 */
int	try_execute_command(t_command *cmd, char ***envp, int *ret, int last_exit)
{
	pid_t	pid;

	*ret = 0;
	pid = fork();
	if (pid == -1)
	{
		print_err("msh_internal: could not setup fork\n");
		return (0);
	}
	if (pid == 0)
	{
		tec_child(cmd, envp, ret, last_exit);
		exit(*ret);
	}
	waitpid(pid, ret, 0);
	if (WIFSIGNALED(*ret) == 1)
	{
		*ret = 128 + WTERMSIG(*ret);
	}
	else if (WIFEXITED(*ret) == 1)
	{
		*ret = WEXITSTATUS(*ret);
	}
	return (1);
}
