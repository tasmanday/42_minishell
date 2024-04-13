/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:48:40 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 18:10:10 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	checks the current command against supported builtins and executes the
	corresponding function.

	Inputs
	[t_msh *] msh: the main minishell structure containing command and
		environment data.
	[t_dlist *] curr_cmd: a pointer to the current command in the command queue.

	Outputs
	none.
*/
/* void	execute_builtin(t_msh *msh, t_dlist *curr_cmd)
{
	t_cmd	*cmd;

	if (!curr_cmd || !curr_cmd->data)
	{
		error("execute_builtin no curr_cmd");
		return ;
	}
	cmd = (t_cmd *)curr_cmd->data;
	if (ft_strcmp(cmd->command, "env") == 0)
		ft_env(msh, cmd);
	else if (ft_strcmp(cmd->command, "pwd") == 0)
		ft_pwd(msh, cmd);
	else if (ft_strcmp(cmd->command, "export") == 0)
		ft_export(msh, cmd);
	else if (ft_strcmp(cmd->command, "echo") == 0)
		ft_echo(msh, cmd);
	else if (ft_strcmp(cmd->command, "exit") == 0)
		ft_exit(msh, cmd);
	else if (ft_strcmp(cmd->command, "cd") == 0)
		ft_cd(msh, cmd);
	else if (ft_strcmp(cmd->command, "unset") == 0)
		ft_unset(msh, cmd);
} */

void	execute_builtin(t_msh *msh, t_dlist *curr_cmd)
{
	t_cmd	*cmd;
	int		status;

	status = 0;
	if (!curr_cmd || !curr_cmd->data)
	{
		error("execute_builtin no curr_cmd");
		return ;
	}
	cmd = (t_cmd *)curr_cmd->data;
	if (ft_strcmp(cmd->command, "env") == 0)
		status = ft_env(msh, cmd);
	else if (ft_strcmp(cmd->command, "pwd") == 0)
		status = ft_pwd(msh, cmd);
	else if (ft_strcmp(cmd->command, "export") == 0)
		status = ft_export(msh, cmd);
	else if (ft_strcmp(cmd->command, "echo") == 0)
		status = ft_echo(msh, cmd);
	else if (ft_strcmp(cmd->command, "exit") == 0)
		status = ft_exit(msh, cmd);
	else if (ft_strcmp(cmd->command, "cd") == 0)
		status = ft_cd(msh, cmd);
	else if (ft_strcmp(cmd->command, "unset") == 0)
		status = ft_unset(msh, cmd);
	msh->last_exit_status = status;
}
