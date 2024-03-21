/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_new_token_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:04:18 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 21:08:11 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for new_node

	Summary
	creates a new node for a linked list and assigns a given string to it.
	it also handles the case when memory allocation fails.

	Inputs
	[t_msh *] msh: a pointer to a t_msh struct, which is the minishell
		program's main data structure.
	[char *] str: a pointer to a string that will be assigned to the new node.

	Outputs
	[t_list *] new_node: a pointer to the newly created node.
*/
t_list	*safe_new_token_node(t_msh *msh, char *str)
{
	t_list	*new_node;

	new_node = lst_new_node(str);
	if (!new_node)
	{
		lst_del_all(&msh->tokens, free_data);
		error_exit("safe_new_token_node_error");
	}
	return (new_node);
}
