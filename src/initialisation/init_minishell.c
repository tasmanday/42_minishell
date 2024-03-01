/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:42:47 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 14:34:18 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	initializes the t_msh structure with environment variables and tokens from
	user input.

	Inputs
	[t_msh *] msh: a pointer to a t_msh structure that will be initialized.
	[char **] argv: an array of strings representing command-line arguments. (will be removed once I have set up termcaps as I will be getting input from the terminal rather than argv then)
	[char **] envv: an array of strings representing environment variables.

	Outputs
	none.
*/
void	init_minishell(t_msh *msh, char **argv, char **envv) // remove argv later when termcaps set up
{
//	int	debug_count;

//	(void)argv;
//	(void)envv;
//	debug_count = -1;
	clone_envv_to_dlist(envv, &msh->envvar);
	get_tokens_from_input(msh, argv); // change function when termcaps set up
//	debug_count = lst_size(msh->tokens);
//	ft_printf("%i\n", debug_count);
}
