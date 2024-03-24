/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envvar_to_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:03:18 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 11:51:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	the returned string is dynamically allocated and should be freed by the
	caller.

	Summary
	rejoins environment variable key and value into a single string.
	
	Inputs
	[t_dlist *] node: a node in the doubly linked list containing the
		environment variable's key and value.
	
	Outputs
	[char *] string: the combined key and value of the environment variable as
		a single string, formatted as 'key=value'.
*/
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

/*
	**** ALLOCATES MEMORY ****
	the returned array and the strings it contains are dynamically allocated and
	should be freed by the caller after use.

	Summary
	converts the list of environment variables from the minishell's linked list
	format into an array format.

	Inputs
	[t_msh *] msh: the main minishell struct containing the environment 
		variables in a doubly linked list.
	
	Outputs
	[char **] array: the environment variables as an array of strings where 
		each string is formatted as 'key=value'.
*/
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
