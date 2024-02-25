/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:45 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 20:45:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	passes the argv strings to add_tokens_to_list which separates them into
	tokens and adds them to a linked list. this function will be replaced when
	termcaps is set up.

	Inputs
	[t_msh *] msh: the main struct which contains a linked list for the tokens.
	[char **] argv: the command line arguments.

	Outputs
	none. 
*/
void	get_tokens_from_input(t_msh *msh, char **argv)
{
	int		i;

	i = 1; // skips ./minishell

	while (argv[i])
	{
		add_tokens_to_list(msh, argv[i]);
		i++;
	}
}
