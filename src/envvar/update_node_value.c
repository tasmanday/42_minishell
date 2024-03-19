/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:38:45 by tday              #+#    #+#             */
/*   Updated: 2024/03/19 23:38:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_node_value(t_dlist *envvar_node, char *new_value)
{
	t_envv	*envv_struct;

	envv_struct = (t_envv *)envvar_node->data;
	if (envv_struct->env_value != NULL)
		free(envv_struct->env_value);
	envv_struct->env_value = new_value;
}
