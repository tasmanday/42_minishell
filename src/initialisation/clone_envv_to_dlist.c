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

/*
	**** ALLOCATES MEMORY ****
	memory allocated for cloned_substrings in ft_split_first

	Summary
	takes a string representing an environmental variable and splits it into
	two substrings based on the first occurrence of the '=' character.

	Inputs
	[char *] envv: a pointer to a string representing an environmental
		variable.

	Outputs
	[char **] cloned_substrs: an array of two strings, where the first element
		is the substring before the '=' character and the second element is the
		substring after the '=' character.
*/
static char	**split_variables(char *envv)
{
	char	**cloned_substrs;

	cloned_substrs = ft_split_first(envv, '=');
	if (!cloned_substrs)
	{
		error("clone_envv ft_split failed");
		return (NULL);
	}
	return (cloned_substrs);
}

/*
	Summary
	takes an array of two strings and creates a t_envv struct by allocating
	memory for it. it then assigns the first string to the env_key field of
	the struct and the second string to the env_value field.

	Inputs
	[char **] cloned_substrs: a pointer to an array of two strings
		representing the cloned substrings.

	Outputs
	[t_envv *] envv_struct: a pointer to a t_envv struct containing the
		env_key and env_value strings.
*/
static t_envv	*put_str_in_envv_struct(char **cloned_substrs)
{
	t_envv	*envv_struct;

	if (!cloned_substrs)
		return (NULL);
	envv_struct = (t_envv *)malloc(sizeof(t_envv));
	if (!envv_struct)
	{
		free_array((void **)cloned_substrs);
		error("clone_envv envv_struct malloc failed");
		return (NULL);
	}
	envv_struct->env_key = cloned_substrs[0];
	envv_struct->env_value = cloned_substrs[1];
	return (envv_struct);
}

/*
	Summary
	adds a t_envv struct to the end of a doubly linked list.

	Inputs
	[t_dlist **] env_list: a pointer to a doubly linked list.
	[t_envv *] envv_struct: a pointer to a t_envv struct.

	Outputs
	none.
*/
static void	add_envv_to_dlist(t_msh *msh, t_dlist **env_list, t_envv *s_envv)
{
	t_dlist	*new_node;

	if (!s_envv)
		msh_error_exit(msh, "clone_envv no envv_struct");
	new_node = dlst_new_node(s_envv);
	if (!new_node)
		msh_error_exit(msh, "clone_envv new_node malloc error");
	dlst_add_tail(env_list, new_node);
}

/*
	**** ALLOCATES MEMMORY ****
	for each environmental veriable, memory is allocated for:
	- a cloned string
	- a t_envv struct
	- a t_dlist node
	when freeing:
	for each node, free the envv_struct->env_variables, then the t_envv struct,
	then lastly the t_dlist node.

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

*/
void	clone_envv_to_dlist(t_msh *msh, char **envv, t_dlist **envvar)
{
	char	**cloned_substrs;
	t_envv	*envv_struct;

	while (*envv)
	{
		cloned_substrs = split_variables(*envv);
		envv_struct = put_str_in_envv_struct(cloned_substrs);
		add_envv_to_dlist(msh, envvar, envv_struct);
		free(cloned_substrs);
		envv++;
	}
}
