/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:48:33 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 19:46:10 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

void	execute_child(t_msh *msh, char **env, char **arg, t_cmd *cmd_data)
{
	char	*path;

	if (has_path(arg[0]))
	{
	//	debug("HAS PATH");
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
