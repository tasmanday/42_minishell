/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:23:16 by tday              #+#    #+#             */
/*   Updated: 2024/03/06 22:21:25 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlist	*clone_list(t_dlist *original)
{
	t_dlist	*new_list;
	t_dlist	*new_node;
	void	*envv;

	new_list = NULL;
	while (original != NULL)
	{
		envv = original->data;
		new_node = dlst_new_node(envv);
		if (!new_list)
		{
			error("clone list new node error\n";
			return (NULL);
		}
		dlst_add_tail(&new_list, new_node);
		original = original->next;
	}
	return (new_list);
}

void	export_no_args(msh)
{
	t_dlist	*cloned_list;
	t_dlist	*curr_variable;
	t_envv	*data;

	cloned_list = clone_list(msh->envvar);
	curr_variable = cloned_list;
	// while (curr->next != NULL)
	//	 bubble sort cloned list using ft_strcmp
	// curr_variable = cloned list head
	while (curr_variable)
	{
		data = (t_envv *)curr_variable->data;
		if (data->value == NULL)
			ft_printf("declare -x %s\n", data->key);
		else
			ft_printf("declare -x %s=\"%s\"\n", data->key, data->value);
		curr_variable =curr_variable->next;
	}
	// free cloned list
}

void	ft_export(t_msh *msh)
{
	t_list	*curr_token;
	char	*command;
	char	**var_array;

	curr_token = msh->tokens;
	command = (char *)curr_token->data;
	if (command == "export" && !curr_token->next)
		export_no_args(msh); // write function to handle export with no arguments
	else if (command == "export" && curr_token->next)
		export_args(msh); // write function to handle export with arguments
}
