/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:48:40 by tday              #+#    #+#             */
/*   Updated: 2024/03/14 22:22:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_builtin(t_msh *msh)
{
	t_cmd	*cmd_struct = (t_cmd *)msh->cmd_queue->data;

	if (!msh->cmd_queue)
	{
		error("execute_builtin no cmd_queue");
		return ;
	}
	if (ft_strcmp(cmd_struct->command, "env") == 0)
		ft_env(msh);
	else if (ft_strcmp(cmd_struct->command, "pwd") == 0)
		ft_pwd(msh);
	else if (ft_strcmp(cmd_struct->command, "export") == 0)
		ft_export(msh);
	else if (ft_strcmp(cmd_struct->command, "echo") == 0)
		ft_echo(msh);
	else if (ft_strcmp(cmd_struct->command, "exit") == 0)
	{
		error("exit not coded yet");
		return ;
	}
	else if (ft_strcmp(cmd_struct->command, "cd") == 0)
	{
		error("cd not coded yet");
		return ;
	}
	else if (ft_strcmp(cmd_struct->command, "unset") == 0)
		ft_unset(msh);
}
