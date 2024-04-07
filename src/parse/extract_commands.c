/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:13:44 by tday              #+#    #+#             */
/*   Updated: 2024/04/07 17:13:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the string in the command element

	Summary
	fills the command element of a t_cmd structure with the data from the
	current token in the token list. If the command is a pipe symbol (|),
	it sets the is_pipe flag to true.

	Inputs
	[t_cmd *] cmd: a pointer to a t_cmd structure that needs to be filled
		with data.
	[t_list **] curr_token_ptr: a pointer to the current token in the token
		list.

	Outputs
	none. it modifies the "command" and "is_pipe" elements of the cmd
	structure.
*/
static void	fill_command_element(t_cmd *cmd, t_list **curr_token_ptr)
{
	cmd->command = ft_strdup((char *)(*curr_token_ptr)->data);
	if (!cmd->command)
		error_exit("extract_commands strdup error");
}

/*
	Summary
	checks if a given string is a redirection symbol.

	Inputs
	[char *] str: The string to be checked for redirection symbol.

	Outputs
	returns true if the given string is a redirection symbol, and false
	if it's not.
*/
bool	is_redirect(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<") || \
		!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (true);
	else
		return (false);
}

/*
	**** ALLOCATES MEMORY ****
	memory allocated for the argument and the list node

	Summary
	adds tokens representing command line arguments to arguments list within
	cmd struct.

	Inputs
	[t_msh *] msh: a pointer to the main shell structure.
	[t_cmd *] cmd: the command struct that contains the "arguments" linked list
		to be filled.
	[char *] data: the token string to be added to the "arguments" linked list.

	Outputs
	none. modifies the msh->cmd_queue->arguments linked list.
*/
void	add_args_to_cmd(t_msh *msh, t_cmd *cmd, char *data)
{
	char	*arg;
	t_list	*arg_node;

	arg = ft_strdup(data);
	arg_node = lst_new_node(arg);
	if (!arg_node)
	{
		free_cmd_struct(cmd);
		msh_error_exit(msh, "fill_cmd_struct error");
	}
	lst_add_tail(&(cmd->arguments), arg_node);
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for cmd struct

	Summary
	fills a cmd structure with data from a list of tokens

	Inputs
	[t_msh *] msh: a pointer to the main shell structure.
	[t_list **] curr_token_ptr: a pointer to the current token in the list.

	Outputs
	[t_cmd *] cmd: a filled command structure.
*/
static t_cmd	*fill_cmd_struct(t_msh *msh, t_list **curr_token_ptr)
{
	t_cmd	*cmd;
	t_list	*token;

	if (!curr_token_ptr || !*curr_token_ptr)
		return (error("fill_cmd_struct no token_ptr"), NULL);
	if (ft_strcmp((char *)(*curr_token_ptr)->data, "|") == 0)
		*curr_token_ptr = (*curr_token_ptr)->next;
	cmd = safe_calloc(1, sizeof(t_cmd), "extract_commands cmd malloc error");
	cmd->in_fd = STDIN_FILENO;
	cmd->out_fd = STDOUT_FILENO;
	fill_command_element(cmd, curr_token_ptr);
	token = (*curr_token_ptr)->next;
	while (token && ft_strcmp((char *)token->data, "|") != 0)
	{
		if (token->next && is_redirect((char *)token->data))
			handle_redirection(cmd, &token);
		else
			add_args_to_cmd(msh, cmd, (char *)token->data);
		token = token->next;
	}
	*curr_token_ptr = token;
	return (cmd);
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for nodes of the doubly linked list in the
	dlst_new_node function needs to be freed at the end of program.

	Summary
	adds a node containing the given command structure to the msh->cmd_queue
	doubly linked list.

	Inputs
	[t_msh *] msh: a pointer to the main shell structure.
	[t_cmd *] cmd_struct: the command structure to be added to the list.

	Outputs
	none. modifies the msh->cmd_queue doubly linked list.
*/
void	add_cmd_to_dlist(t_msh *msh, t_cmd *cmd_struct)
{
	t_dlist	*new_node;

	if (!cmd_struct)
		msh_error_exit(msh, "extract_commands no cmd_struct");
	new_node = dlst_new_node(cmd_struct);
	if (!new_node)
		msh_error_exit(msh, "extract_command new_node malloc error");
	dlst_add_tail(&(msh->cmd_queue), new_node);
}

/*
	**** ALLOCATES MEMORY ****	
	memory is allocated in subfunctions

	Summary
	parses a list of tokens creating a command queue, commands are separated by
	pipe symbols '|'

	Inputs
	[t_msh *] msh: a pointer to the main shell structure, which contains the
		list of tokens to be parsed and the cmd_queue to be filled.

	Outputs
	none. the function modifies the msh structure by creating a command queue
	based on the token list.
*/
void	extract_commands(t_msh *msh)
{
	t_list	*curr_token;
	t_cmd	*cmd_struct;

	curr_token = msh->tokens;
	while (curr_token)
	{
		cmd_struct = fill_cmd_struct(msh, &curr_token);
		if (cmd_struct->is_append == true)
			debug("is_append");
		add_cmd_to_dlist(msh, cmd_struct);
		msh->num_of_cmds++;
	}
	free_tokens(msh);
}