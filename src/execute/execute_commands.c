/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:36:45 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 14:51:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	get_pid_exit_status(t_msh *msh, t_list **pids)
{
	int		*pid;
	int		exit_status;

	exit_status = 0;
	while(*pids)
	{
		pid = (int *)(*pids)->data;
		waitpid(*pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			msh->last_exit_status = WEXITSTATUS(exit_status);
		else if (WIFSIGNALED(exit_status))
			msh->last_exit_status = WTERMSIG(exit_status);
		lst_del_head(pids, free_data);
	}
}

void	execute_commands(t_msh *msh)
{
	t_dlist	*curr_cmd;
	t_cmd	*cmd_data;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = (t_cmd *)curr_cmd->data;
		if (cmd_is_builtin(cmd_data->command))
			execute_builtin(msh, curr_cmd);
		else
		execute_parent(msh, cmd_data);
		curr_cmd = curr_cmd->next;
	}
	get_pid_exit_status(msh, &msh->pids);
}
