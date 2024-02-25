/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:52:38 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 15:28:24 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	prints the value of the env_value field of a given t_envv structure.

	Inputs
	[t_envv *] envv_element: a pointer to a t_envv structure that contains the
	value to be printed.

	Outputs
	none.
*/
static void	print_env_value(t_envv *envv_element)
{
	if (envv_element != NULL)
	{
		ft_printf("%s\n", envv_element->env_value);
	}
}

/*
	Summary
	prints the current working directory to the standard output.

	Inputs
	[t_msh *] msh: the main struct of minishell contianing a doubly linked
		list of cloned environment variables.

	Outputs
	none.
*/
void	ft_pwd(t_msh *msh)
{
	t_dlist	*pwd_node;

	pwd_node = find_envvar_node(msh->envvar, "PWD");
	print_env_value((t_envv *)pwd_node->data);
}
