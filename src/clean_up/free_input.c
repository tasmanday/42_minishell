/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:34:36 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 15:43:56 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
 	frees all allocated resources associated with the command input.

 	Inputs
 	[t_msh *] msh: minishell main structure containing the command queue and
		tokens that need to be freed.
	[char *] input: the user input string that needs to be freed.

 	Outputs
 	none. function just frees allocated memory.
*/
void	free_input(t_msh *msh)
{
	if (msh->cmd_queue)
	{
		dlst_del_all(&(msh->cmd_queue), free_cmd_struct);
		msh->cmd_queue = NULL;
	}
	if (msh->tokens)
	{
		lst_del_all(&(msh->tokens), free_data);
		msh->tokens = NULL;
	}
	if (msh->input)
	{
		free(msh->input);
		msh->input = NULL;
	}
}
