/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:00:45 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 21:16:39 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees the memory allocated and deletes all nodes for a linked list of
	strings (msh->tokens).

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.

	Outputs
	none. the tokens linked list is freed and deleted.
*/
void	free_tokens(t_msh *msh)
{
	lst_del_all(&(msh->tokens), free_data);
	msh->tokens = NULL;
}
