/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:11:21 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 19:19:14 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	removes environmental variables with keys matching the provided arguments.

	Inputs
	[t_msh *] msh: the main struct of the minishell, contains the command queue
		and environment variable list.

	Outputs
	none. the function modifies the msh->envvar doubly linked list by removing
	the environment variables specified in cmd_struct->arguments.
*/
void	ft_unset(t_msh *msh)
{
	t_cmd	*cmd_struct;
	t_list	*args;
	t_dlist	*env_node;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
		return ;
	else
	{
		args = cmd_struct->arguments;
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
}
