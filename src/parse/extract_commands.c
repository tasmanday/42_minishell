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

t_cmd	*fill_cmd_struct(t_list *token)
{
	t_cmd	*cmd;
	t_list	*arg_node;

	if (!token)
		// error handle
	cmd = safe_malloc(sizeof(t_cmd), \
		"extract_commands cmd malloc error");
	cmd->command = (char *)token->data;
	token = token->next;
	while (token && ft_strcmp((char *)token->data, "|") != 0)
	{
		if (token->next && ft_strcmp((char *)token->data, "<") == 0)
		{
			token = token->next;
			cmd->input = (char *)token->data;
		}
		else if (token->next && ft_strcmp((char *)token->data, "<") == 0)
		{
			token = token->next;
			cmd->input = (char *)token->data;
		}
		else
		{
			arg_node = lst_new_node(token->data);
			if (!arg_node)
				// error handle
			lst_add_tail(&(cmd->arguments), arg_node);
		}
		token = token->next;
	}
}

void	extract_commands(t_msh *msh)
{
	t_list	*curr_token;
	t_cmd	*cmd_struct;

	curr_token = msh->tokens;
	while (curr_token)
	{
		cmd_struct = fill_cmd_struct(&curr_token); // write function
		add_cmd_to_list(cmd_struct); // write function
	}
}
