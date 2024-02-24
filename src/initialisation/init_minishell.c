/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:42:47 by tday              #+#    #+#             */
/*   Updated: 2024/02/24 14:42:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_minishell(t_msh *msh, char **argv, char **envv) // remove argv later when termcaps set up
{
	clone_envv_to_dlist(envv, msh->envvar);
	get_tokens_from_input(msh, argv);
}