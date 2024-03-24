/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:38:45 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 13:40:32 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	updates the env_value element of an environmental variable node. if a value
	already exists it it freed before being updated.

	Inputs
	[t_dlist *] envvar_node: the node in a doubly linked list to be updated.
	[char *] new_value: the new value to be assigned to the env_value field.

	Outputs
	none. the function updates the value of the env_value field in the t_envv
	structure.
*/
void	update_node_value(t_dlist *envvar_node, char *new_value)
{
	t_envv	*envv_struct;

	envv_struct = (t_envv *)envvar_node->data;
	if (envv_struct->env_value != NULL)
		free(envv_struct->env_value);
	envv_struct->env_value = new_value;
	if (new_value != NULL)
	{
		envv_struct->env_value = ft_strdup(new_value);
		if (envv_struct->env_value == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		envv_struct->env_value = NULL;
	}
}
