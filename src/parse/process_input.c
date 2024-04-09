/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:29:36 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 10:33:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	processes the user's input in the minishell environment.
	
	Inputs
	[t_msh *] msh: the main minishell struct.
	[char *] input: the input string to be processed.
	
	Outputs:
	none. the function modifies the shell environment by adding tokens and
	extracting commands based on the input.
*/
/* void	process_input(t_msh *msh, char *input)
{
	if (!input || input[0] == '\0')
		return ;
	add_tokens_to_list(msh, input);
	extract_commands(msh);
	process_fds(msh);
} */

void	process_input(t_msh *msh)
{
	add_tokens_to_list(msh);
	extract_commands(msh);
	process_fds(msh);
}