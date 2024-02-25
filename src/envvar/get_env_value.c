/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:11:43 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 22:19:24 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	searches for a node in the linked list that matches the given key and
	returns the corresponding environment value if found.

	Inputs
	[t_dlist] envvar: a doubly linked list of environment variables
	[char *] key: a string representing the key of the environment variable
		to search for
	
	Outputs
	if a node with the given key is found in the linked list, the function
		returns the corresponding environment value.
	otherwise, the function returns NULL.
*/
char	*get_env_value(t_dlist *envvar, char *key)
{
	t_dlist	*node;
	t_envv	*envv_struct;

	node = find_envvar_node(envvar, key);
	if (!node)
		return (NULL);
	envv_struct = (t_envv *)node->data;
	return (envv_struct->env_value);
}
