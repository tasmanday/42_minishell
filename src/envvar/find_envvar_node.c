/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envvar_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:04:47 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 21:50:30 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	finds a node in a doubly linked list based on a given key string.

	Inputs
	[t_dlist *] envvar: a pointer to the head of the doubly linked list.
	[char *] key: the key string to search for in the list.

	Outputs
	a pointer to the node with the matching key if found or NULL if no node
	with the matching key is found in the list.
*/
t_dlist	*find_envvar_node(t_dlist *envvar, char *key)
{
	t_dlist	*current;
	t_envv	*envv_struct;

	current = envvar;
	while (current)
	{
		envv_struct = (t_envv *)current->data;
		if (ft_strcmp(key, envv_struct->env_key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
