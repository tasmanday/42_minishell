/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:36:45 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:06:36 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Retrieves the exit status of child processes and updates the last exit
	status of the minishell.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.
	[t_list **] pids: Pointer to the list of process IDs.

	Outputs
	None. Updates the last exit status of the minishell based on the exit
	status of child processes.
*/
void	get_pid_exit_status(t_msh *msh, t_list **pids)
{
	int		*pid;
	int		exit_status;

	exit_status = 0;
	while (*pids)
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

/*
	Summary
	Executes commands in the minishell, including built-in commands and external
	commands.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	None. Executes commands and updates the minishell state accordingly.
*/

void	execute_commands(t_msh *msh)
{
	t_dlist	*curr_cmd;
	t_cmd	*cmd_data;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = (t_cmd *)curr_cmd->data;
		if (ft_strcmp(cmd_data->command, "print_paths") == 0)
			print_paths(msh);
		else if (cmd_is_builtin(cmd_data->command))
			execute_builtin(msh, curr_cmd);
		else
			execute_parent(msh, cmd_data);
		curr_cmd = curr_cmd->next;
	}
	get_pid_exit_status(msh, &msh->pids);
}
