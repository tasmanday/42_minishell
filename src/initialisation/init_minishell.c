/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:42:47 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 10:14:14 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Increments the shell level (SHLVL) in the minishell environment.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	None. Modifies the SHLVL environment variable stored in the minishell
 	structure.
*/
static void	increment_shlvl(t_msh *msh)
{
	t_dlist	*node;
	t_envv	*envv_struct;

	node = find_envvar_node(msh->envvar, "SHLVL");
	envv_struct = node->data;
	envv_struct->env_value[0]++;
	if (envv_struct->env_value[0] > '9')
		debug("please stop opening shells, I can't count this high 😥");
}

/*
	Summary
	initializes the t_msh structure with environment variables, increments
 	the shell level, and sets up the signal handlers.

	Inputs
	[t_msh *] msh: the t_msh structure that will be initialized.
	[char **] envv: an array of strings representing environment variables.

	Outputs
	none.
*/
t_msh	*init_minishell(char **envv)
{
	t_msh	*msh;

	msh = safe_calloc(1, sizeof(t_msh), "msh malloc error");
	clone_envv_to_dlist(msh, envv);
	increment_shlvl(msh);
	setup_signal_handlers();
	return (msh);
}
