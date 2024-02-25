/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_new_token_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:04:18 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 22:25:30 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
*/
t_list	*safe_new_token_node(t_msh *msh, char *str)
{
	t_list	*new_node;

	new_node = lst_new_node(str);
	if (!new_node)
	{
		lst_del_all(&msh->tokens, free_string);
		error_exit("safe_new_token_node_error");
	}
	return (new_node);
}
