/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:13:44 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 18:29:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	handle_redirection(t_cmd **cmd, t_list **token_ptr)
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
	}
}

static void	fill_command_element(t_cmd **cmd, t_list **curr_token_ptr)
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

static t_cmd	*fill_cmd_struct(t_msh *msh, t_list **curr_token_ptr)
{
	t_cmd	*cmd;
	t_list	*arg_node;
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
		if (token->next && (ft_strcmp((char *)token->data, "<") == 0 || ft_strcmp((char *)token->data, ">") == 0)) // update to (token->next && is_redirect((char *)token->data)) is_redirect() needs to be created
			handle_redirection(&cmd, &token);
		else
		{
			arg_node = lst_new_node(token->data);
			if (!arg_node)
				{
					free_cmd_struct(cmd);
					msh_error_exit(msh, "fill_cmd_struct error");
				}
			lst_add_tail(&(cmd->arguments), arg_node);
		}
		token = token->next;
	}
	*curr_token_ptr = token;
	return (cmd);
}

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
	debug("about to free_tokens");
	free_tokens(msh);
}
