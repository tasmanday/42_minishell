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
	
	Outputs:
	none. the function modifies the shell environment by adding tokens,
	extracting commands, and setting up file descriptors based on the
 	input.
*/

void	process_input(t_msh *msh)
{
	add_tokens_to_list(msh);
	extract_commands(msh);
	process_fds(msh);
}
