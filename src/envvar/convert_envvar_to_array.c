/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envvar_to_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:03:18 by tday              #+#    #+#             */
/*   Updated: 2024/03/23 16:26:01 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*rejoin_env_strings(t_dlist *node)
{
	t_envv	*envv_struct;
	int		key_len;
	int		value_len;
	char	*string;

	envv_struct = (t_envv *)node->data;
	key_len = ft_strlen(envv_struct->env_key);
	value_len = ft_strlen(envv_struct->env_value);
	string = (char *)safe_calloc(key_len + value_len + 2, sizeof(char), \
		"rejoin_env_strings calloc error");
	ft_strcpy(string, envv_struct->env_key);
	string[key_len] = '=';
	ft_strcpy(&string[key_len + 1], envv_struct->env_value);
	return (string);
}

char	**convert_envvar_to_array(t_msh *msh)
{
	char	**array;
	int		i;
	int		length;
	t_dlist	*curr_node;

	i = 0;
	curr_node = msh->envvar;
	length = dlst_size(msh->envvar);
	array = (char **)safe_calloc(length + 1, sizeof(char *), \
		"convert_envvar_to_array error");
	while (i < length)
	{
		array[i++] = rejoin_env_strings(curr_node);
		curr_node = curr_node->next;
	}
	return (array);
}
