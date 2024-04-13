/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:11:21 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 16:47:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	removes environmental variables with keys matching the provided arguments.

	Inputs
	[t_msh *] msh: the main struct of the minishell, contains the environment
		variable list.
	[t_cmd *] cmd: the command struct containing the data from the current
		command.

	Outputs
	none. the function modifies the msh->envvar doubly linked list by removing
	the environment variables specified in cmd_struct->arguments.
*/
/* void	ft_unset(t_msh *msh, t_cmd *cmd)
{
	t_list	*args;
	t_dlist	*env_node;

	if (!cmd->arguments)
		return ;
	else
	{
		args = cmd->arguments;
		while (args)
		{
			env_node = find_envvar_node(msh->envvar, (char *)args->data);
			if (!env_node)
			{
				args = args->next;
				continue ;
			}
			dlst_del_node(&msh->envvar, env_node, free_envv_struct);
			args = args->next;
		}
	}
} */

int	ft_unset(t_msh *msh, t_cmd *cmd)
{
	t_list	*args;
	t_dlist	*env_node;

	if (!cmd->arguments)
	{
		msh->last_exit_status = 0;
		return (0);
	}
	args = cmd->arguments;
	while (args)
	{
		env_node = find_envvar_node(msh->envvar, (char *)args->data);
		if (env_node)
			dlst_del_node(&msh->envvar, env_node, free_envv_struct);
		args = args->next;
	}
	msh->last_exit_status = 0;
	return (0);
}
