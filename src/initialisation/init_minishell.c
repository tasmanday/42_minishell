/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:42:47 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 14:53:36 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_minishell(t_msh *msh, char **argv, char **envv) // remove argv later when termcaps set up
{
	int	debug_count;

	debug_count = -1;
	clone_envv_to_dlist(envv, &msh->envvar);
	get_tokens_from_input(msh, argv);
	debug_count = lst_size(msh->tokens);
	ft_printf("%i\n", debug_count);
}
