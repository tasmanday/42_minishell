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

void	execute_commands(t_msh *msh)
{
	t_dlist	*curr_cmd;
	t_cmd	*cmd_data;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = (t_cmd *)curr_cmd->data;
		if (cmd_is_builtin(cmd_data->command))
			execute_builtin(msh);
		else
		execute_parent(msh, cmd_data);
		//put pid exit status's in msh
	}
}
