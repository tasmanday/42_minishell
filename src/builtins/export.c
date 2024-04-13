/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:23:16 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 16:45:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the cloned dlist which is returned. this needs to
	be freed by the calling function once it is no longer needed.

	Summary
	clones a doubly linked list by creating a new list and copying the data from
	each node of the original list to the new list.

	Inputs
	[t_dlist *] original: the original doubly linked list to be cloned.

	Outputs
	[t_dlist *] new_list: the cloned doubly linked list.
*/
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

/*
	Summary
	sorts the dlist of environmental variables into ASCII order based on their
	env_key elements.

	Inputs
	[t_dlist **] head: the head of the doubly linked list to be sorted.

	Outputs
	none. the given dlist itself is sorted.
*/
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

/*
	**** ALLOCATES MEMORY ****
	memory is allocated in a subfunction but freed in this function.

	Summary
	handles export without arguments.
	sorts the environmental variables to ASCII order and prints them to the
	terminal with a "declare -x" prefix.

	Inputs
	[t_msh *] msh: the main struct of the minishell, contains the command queue
		and environment variable list.
	[t_cmd *] cmd: the command struct containing the data from the current
		command.

	Outputs
	none. the function prints the environment variables to the console.
*/
/* static void	export_no_args(t_msh *msh, t_cmd *cmd)
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
			ft_printf_fd(cmd->out_fd, "declare -x %s\n", data->env_key);
		else
			ft_printf_fd(cmd->out_fd, "declare -x %s=\"%s\"\n", data->env_key, \
				data->env_value);
		curr_variable = curr_variable->next;
	}
	free_cloned_list(cloned_list);
} */

static int	export_no_args(t_msh *msh, t_cmd *cmd)
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
			ft_printf_fd(cmd->out_fd, "declare -x %s\n", data->env_key);
		else
			ft_printf_fd(cmd->out_fd, "declare -x %s=\"%s\"\n", data->env_key, \
				data->env_value);
		curr_variable = curr_variable->next;
	}
	free_cloned_list(cloned_list);
	msh->last_exit_status = 0;
	return (0);
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated when creating or updating nodes of envvar dlist.
	it needs to be freed at the end of the program.

	Summary
	handles export with arguments.
	iterates through the arguments checking if they are existing environmental
	variables. if they exist it updates the value, otherwise it creates a new
	environment variable and adds it to the list.

	Inputs
	[t_msh *] msh: the main struct of the minishell, contains the command queue
		and environment variable list.
	[t_cmd *] cmd_struct: the command struct, which contains the arguments for
		exporting the environment variables.
	
	Outputs
	none. the function exports the environment variables based on the provided
	arguments.
*/
/* static void	export_args(t_msh *msh, t_cmd *cmd_struct)
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
} */

static int	export_args(t_msh *msh, t_cmd *cmd_struct)
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
	msh->last_exit_status = 0;
	return (0);
}

/*
	**** ALLOCATES MEMORY ****
	subfunctions allocate memory. they also free that memory except for new
	nodes added to the envvar dlist. these need to be freed at the end of the
	program.

	Summary
	checks if there are any arguments provided with the command. if there are
	no arguments, it exports all the environment variables. if there are
	arguments, it updates the values of existing variables or adds new variables
	to the environment.

	Inputs
	[t_msh *] msh: the main struct of the minishell, contains the command queue
		and environment variable list.
	[t_cmd *] cmd: the command struct containing the data from the current
		command.

	Outputs
	none. the function exports the environmental variables based on the provided
	arguments.
*/
/* void	ft_export(t_msh *msh, t_cmd *cmd)
{
	if (!cmd->arguments)
		export_no_args(msh, cmd);
	else
		export_args(msh, cmd);
} */

int	ft_export(t_msh *msh, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (!cmd->arguments)
		status = export_no_args(msh, cmd);
	else
		status = export_args(msh, cmd);
	msh->last_exit_status = 0;
	return (status);
}
