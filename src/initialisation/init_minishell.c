/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:42:47 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 18:29:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	initializes the t_msh structure with environment variables

	Inputs
	[t_msh *] msh: a pointer to a t_msh structure that will be initialized.
	[char **] envv: an array of strings representing environment variables.

	Outputs
	none.
*/
t_msh	*init_minishell(char **envv)
{
	t_msh	*msh;

	msh = safe_calloc(1, sizeof(t_msh), "msh malloc error");
	clone_envv_to_dlist(msh, envv);
	return (msh);
}
