/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:28 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 14:51:25 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees all remaining allocated memory in the msh struct. this function is
	called when exiting the minishell program to avoid memory leaks.

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.

	Outputs
	none. all allocated memory and structs are freed and deleted.
*/
void	free_everything(t_msh *msh)
{
	if (msh)
	{
		if (msh->envvar)
		{
			dlst_del_all(&(msh->envvar), free_envv_struct);
			msh->envvar = NULL;
		}
		if (msh->tokens)
		{
			lst_del_all(&(msh->tokens), free_data);
			msh->tokens = NULL;
		}
		if (msh->cmd_queue)
		{
			dlst_del_all(&(msh->cmd_queue), free_cmd_struct);
			msh->cmd_queue = NULL;
		}
		if (msh->pids)
		{
			lst_del_all(&(msh->pids), free_data);
			msh->pids = NULL;
		}
		if (msh->input)
			free(msh->input);
		free(msh);
	}
}
