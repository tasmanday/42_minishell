/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envv_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:25:10 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 14:34:04 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees the memory allocated for a t_envv structure. this function can be
	passed to dlist_del_all() to free allocated memory at each node of a doubly
	linked list before deleting them.

	Inputs
	[void *] data: a pointer to a t_envv structure that needs to be freed.

	Outputs
	none. The function frees the memory allocated for the t_envv structure.
*/
void	free_envv_struct(void *data)
{
	t_envv	*envv;

	envv = (t_envv *)data;
	if (envv)
	{
		if (envv->env_key)
			free(envv->env_key);
		if (envv->env_value)
			free(envv->env_value);
		free(envv);
	}
}
