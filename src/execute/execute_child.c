/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:48:33 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:05:17 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Updates file descriptors for input and output redirection.

	Inputs
	[t_cmd **] cmd_data: Pointer to the command structure.

	Outputs
	None. Modifies file descriptors for input and output redirection.
*/
static void	update_fds(t_cmd **cmd_data)
{
	if ((*cmd_data)->in_fd != STDIN_FILENO)
	{
		dup2((*cmd_data)->in_fd, STDIN_FILENO);
		close((*cmd_data)->in_fd);
	}
	if ((*cmd_data)->out_fd != STDOUT_FILENO)
	{
		dup2((*cmd_data)->out_fd, STDOUT_FILENO);
		close((*cmd_data)->out_fd);
	}
}

/*
	Summary
	Checks if a command has includes a path, if it doesn't it finds the correct
	path and then executes the command in the child process.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.
	[char **] env: Array of strings representing environment variables.
	[char **] arg: Array of strings representing command arguments.
	[t_cmd *] cmd_data: Pointer to the command structure containing input file,
		input and output file descriptors.

	Outputs
	None. Executes the command in the child process.
*/
void	execute_child(t_msh *msh, char **env, char **arg, t_cmd *cmd_data)
{
	char	*path;

	if ((cmd_data->input_file && !file_exists(cmd_data->input_file)) || \
		cmd_data->in_fd == -1)
		msh_error_exit(msh, "");
	if (has_path(arg[0]))
	{
		path = ft_strdup(arg[0]);
		if (!path)
			msh_error_exit(msh, "execute_child path error");
	}
	else
		path = get_path(msh, arg[0]);
	if (!path)
	{
		msh->last_exit_status = 127;
		msh_error_exit(msh, "command not found");
	}
	update_fds(&cmd_data);
	execve(path, arg, env);
}
