/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:23:16 by tday              #+#    #+#             */
/*   Updated: 2024/03/14 22:22:24 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlist	*clone_list(t_dlist *original)
{
	t_dlist	*new_list;
	t_dlist	*new_node;
	void	*envv;

	new_list = NULL;
	while (original != NULL)
	{
		envv = original->data;
		new_node = dlst_new_node(envv);
		if (!new_node)
		{
			error("clone list new node error\n");
			return (NULL);
		}
		dlst_add_tail(&new_list, new_node);
		original = original->next;
	}
	return (new_list);
}

static void	sort_dlist(t_dlist **head)
{
	t_dlist	*curr;
	t_envv	*curr_envv;
	t_envv	*next_envv;

	curr = *head;
	while (curr->next != NULL)
	{
		curr_envv = (t_envv *)(curr->data);
		next_envv = (t_envv *)(curr->next->data);
		if (ft_strcmp(curr_envv->env_key, next_envv->env_key) > 0)
		{
			dlst_swap_nodes(head, curr, curr->next);
			curr = *head;
		}
		else
			curr = curr->next;
	}
}

static void	export_no_args(t_msh *msh)
{
	t_dlist	*cloned_list;
	t_dlist	*curr_variable;
	t_envv	*data;

	cloned_list = clone_list(msh->envvar);
	sort_dlist(&cloned_list);
	curr_variable = cloned_list;
	while (curr_variable)
	{
		data = (t_envv *)curr_variable->data;
		if (data->env_value == NULL)
			ft_printf("declare -x %s\n", data->env_key);
		else
			ft_printf("declare -x %s=\"%s\"\n", data->env_key, data->env_value);
		curr_variable = curr_variable->next;
	}
	free_cloned_list(cloned_list);
}

static void	export_args(t_msh *msh, t_cmd *cmd_struct)
{
	char	**str_array;
	t_list	*args;
	t_envv	*envv_struct;
	t_dlist	*node_exists;

	args = cmd_struct->arguments;
	while (args)
	{
		str_array = split_variables((char *)args->data);
		node_exists = find_envvar_node(msh->envvar, str_array[0]);
		if (node_exists)
		{
			update_node_value(node_exists, str_array[1]);
			free(str_array[0]);
		}
		else
		{
			envv_struct = put_str_in_envv_struct(str_array);
			add_envv_to_dlist(msh, envv_struct);
		}
		free(str_array);
		args = args->next;
	}
}

void	ft_export(t_msh *msh)
{
	t_cmd	*cmd_struct;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
		export_no_args(msh);
	else 
		export_args(msh, cmd_struct);
}
