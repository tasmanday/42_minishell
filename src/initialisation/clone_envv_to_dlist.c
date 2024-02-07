/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_envv_to_dlist.c	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:01:28 by tday              #+#    #+#             */
/*   Updated: 2024/02/07 22:01:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*copy_string(char *envv)
{
	char	*cloned_string;

	cloned_string = ft_strdup(envv);
	if (!cloned_string)
		error_exit("clone_envv ft_str_dup failed");
	return (cloned_string);
}

static t_envv	*put_str_in_envv_struct(char *cloned_string)
{
	t_envv	*envv_struct;

	envv_struct = (t_envv *)malloc(sizeof(t_envv));
	if (!envv_struct)
	{
		free(cloned_string);
		error_exit("clone_envv envv_struct malloc failed");
	}
	envv_struct->env_variable = cloned_string;
	return (envv_struct);
}

static void	add_envv_struct_to_dlist(t_dlist **env_list, t_envv *envv_struct)
{
	t_dlist	*new_node;

	new_node = dlst_new_node(envv_struct);
	if (!new_node)
	{
		free(envv_struct->env_variable);
		free(envv_struct);
		error_exit("clone_envv new_node malloc error");
	}
	dlst_add_tail(env_list, new_node);
}

/*
	Summary
	duplicates the environmental variable strings, wraps them in a t_envv struct
	and then inserts them into a doubly linked list.

	Inputs
	[char **] envv: A pointer to an array of strings representing the
	environmental variables.
	[t_dlist **] env_list: A pointer to a doubly linked list.

	Outputs
	none. the function modifies the env_list doubly linked list by adding the
	duplicated environmental variable strings wrapped in t_envv structs.

	Memory
	for each environmental veriable, memory is allocated for:
	- a cloned string
	- a t_envv struct
	- a t_dlist node
	when freeing:
	for each node, free the envv_struct->env_variable, then the t_envv struct,
	then lastly the t_dlist node.
*/
void	clone_envv_to_dlist(char **envv, t_dlist **env_dlist)
{
	char	*cloned_string;
	t_envv	*envv_struct;

	while (*envv)
	{
		cloned_string = copy_string(*envv);
		envv_struct = put_str_in_envv_struct(cloned_string);
		add_envv_struct_to_dlist(env_dlist, envv_struct);
		envv++;
	}
}
