/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:13:44 by tday              #+#    #+#             */
/*   Updated: 2024/03/11 23:35:43 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	handle_redirection(t_cmd **cmd, t_list **token_ptr) // can probably be cleaned up by using t_cmd *cmd instead
{
	if ((*token_ptr)->next)
	{
		if (ft_strcmp((char *)(*token_ptr)->data, "<") == 0)
		{
			*token_ptr = (*token_ptr)->next;
			(*cmd)->input_file = (char *)(*token_ptr)->data;
		}
		else if (ft_strcmp((char *)(*token_ptr)->data, ">") == 0)
		{
			*token_ptr = (*token_ptr)->next;
			(*cmd)->input_file = (char *)(*token_ptr)->data;
		}
		// update to handle "<<" & ">>"
		else
			error("<< & >> not coded yet");
	}
}

static void	fill_command_element(t_cmd **cmd, t_list **curr_token_ptr) // can probably be cleaned up by using t_cmd *cmd instead
{
	(*cmd)->command = ft_strdup((char *)(*curr_token_ptr)->data);
	if (!(*cmd)->command)
		error_exit("extract_commands strdup error");
	if (ft_strcmp((*cmd)->command, "|") == 0)
	{
		(*cmd)->is_pipe = true;
		*curr_token_ptr = (*curr_token_ptr)->next;
	}
}

bool	is_redirect(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<") || \
		!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (true);
	else
		return (false);
}

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

static t_cmd	*fill_cmd_struct(t_msh *msh, t_list **curr_token_ptr)
{
	t_cmd	*cmd;
	t_list	*token;

	if (!curr_token_ptr || !*curr_token_ptr)
		return (error("fill_cmd_struct no token_ptr"), NULL);
	cmd = safe_calloc(1, sizeof(t_cmd), "extract_commands cmd malloc error");
	fill_command_element(&cmd, curr_token_ptr);
	if (cmd->is_pipe)
		return (cmd);
	token = (*curr_token_ptr)->next;
	while (token && ft_strcmp((char *)token->data, "|") != 0)
	{
		if (token->next && is_redirect((char *)token->data))
			handle_redirection(&cmd, &token);
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
	int		queue = 0;

	curr_token = msh->tokens;
	while (curr_token)
	{
		cmd_struct = fill_cmd_struct(msh, &curr_token);
		add_cmd_to_dlist(msh, cmd_struct);
		queue++;
		debug("commands in queue");
		debug_int(queue);
	}
//	debug("about to free_tokens");
	free_tokens(msh);
}
