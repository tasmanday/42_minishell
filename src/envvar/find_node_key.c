/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:04:47 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 21:50:30 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlist	*find_node_key(t_dlist *envvar, char *key)
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
