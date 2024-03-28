/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:48:40 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 13:40:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* delete when no longer needed */
static void	test(t_msh *msh)
{
	char	**array;
	int		i;
	t_cmd	*cmd_struct;

	i = 0;
	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	array = put_args_in_array(cmd_struct);
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
	debug("array size:");
	debug_int(i);
}

/*
	Summary
	checks the current command against supported builtins and executes the
	corresponding function.

	Inputs
	[t_msh *] msh: the main minishell structure containing command and
		environment data.

	Outputs
	none.
*/
void	execute_builtin(t_msh *msh, t_dlist *curr_cmd)
{
	t_cmd	*cmd_struct;

	if (!curr_cmd || !curr_cmd->data)
	{
		error("execute_builtin no curr_cmd");
		return ;
	}
	cmd_struct = (t_cmd *)curr_cmd->data;
	if (ft_strcmp(cmd_struct->command, "env") == 0)
		ft_env(msh);
	else if (ft_strcmp(cmd_struct->command, "pwd") == 0)
		ft_pwd(msh);
	else if (ft_strcmp(cmd_struct->command, "export") == 0)
		ft_export(msh);
	else if (ft_strcmp(cmd_struct->command, "echo") == 0)
		ft_echo(curr_cmd);
	else if (ft_strcmp(cmd_struct->command, "exit") == 0)
		ft_exit(msh);
	else if (ft_strcmp(cmd_struct->command, "cd") == 0)
		ft_cd(msh);
	else if (ft_strcmp(cmd_struct->command, "unset") == 0)
		ft_unset(msh);
	else if (ft_strcmp(cmd_struct->command, "test") == 0) //remove later
		test(msh);
}
