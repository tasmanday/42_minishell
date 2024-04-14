/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:21 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 17:48:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	prints the key-value pair of an environment variable separated by an '='.

	Inputs
	[int] fd: the file descriptor to output to.
	[t_envv *] envv_element: an environment variable.

	Outputs
	none. the function only prints the key-value pair of the environment
	variable.
*/
static void	print_envvar(int fd, t_envv *envv_element)
{
	if (envv_element != NULL)
	{
		ft_printf_fd(fd, "%s=%s\n", envv_element->env_key, \
		envv_element->env_value);
	}
}

/*
	Summary
	implements the env command in the minishell, printing all environment
	variables.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.
	[t_cmd *] cmd: pointer to the command structure containing output file
		descriptor.

	Outputs
	[int] 0 if successful, 1 if an error occurs.
*/
int	ft_env(t_msh *msh, t_cmd *cmd)
{
	t_dlist	*current;

	current = msh->envvar;
	while (current)
	{
		print_envvar(cmd->out_fd, (t_envv *)current->data);
		current = current->next;
	}
	msh->last_exit_status = 0;
	return (0);
}
