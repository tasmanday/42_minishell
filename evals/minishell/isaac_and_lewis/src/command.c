/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:13:47 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 11:35:04 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

/**
 * @brief Create new command object struct on the heap.
 * 
 * New command struct containing args and redirections. Fills will default
 * "null" values
 * 
 * @return t_command* The new heap t_command struct.
 */
t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command) * 1);
	cmd->args = NULL;
	cmd->redirections = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	return (cmd);
}

/**
 * @brief Delete a heap allocated command struct.
 * 
 * @param cmd The command to be deleted.
 */
void	delete_command(t_command *cmd)
{
	ft_lstclear(&cmd->args, free);
	ft_lstclear(&cmd->redirections, delete_redirection_void);
	free(cmd);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	new_cmd_from_tokens_do_3(t_command *cmd, t_token_node *token)
{
	char	*str;
	t_list	*list_node;

	str = ft_strdup(token->content.str);
	list_node = ft_lstnew(str);
	if (!list_node)
	{
		free(str);
		return (1);
	}
	ft_lstadd_back(&(cmd->args), list_node);
	delete_token_node(token);
	return (0);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	new_cmd_from_tokens_do_4(t_command *cmd, t_deque *tokens)
{
	t_token_node	*token;

	token = ft_deque_popleft(tokens);
	if (!token)
		return (1);
	if (check_one(token))
	{
		if (new_cmd_from_tokens_do_2(cmd, token, tokens))
			return (1);
	}
	else if (token->type == WORD)
	{
		if (new_cmd_from_tokens_do_3(cmd, token))
			return (1);
	}
	else
		delete_token_node(token);
	return (0);
}

/**
 * @brief Create new command object struct on the heap.
 * 
 * Creates and populates with values from the list of tokens. Consumes the
 * tokens in the process.
 * 
 * @param tokens Deque of tokens to turn into a command.
 * @param envv The envv (for expansions).
 * @param last_exit The last exit (for expansions).
 * @return t_command* A new heap command struct with values from the tokens.
 */
t_command	*new_cmd_from_tokens(t_deque *tokens, char **envv, int last_exit)
{
	t_command		*cmd;

	tilde_expand_tokens(*tokens, envv);
	expand_tokens(*tokens, envv, last_exit);
	split_words(tokens);
	filename_expansion(tokens);
	remove_empty_words(tokens);
	remove_quotes_tokens(tokens);
	cmd = new_command();
	if (!cmd)
		return (NULL);
	while (1)
	{
		if (new_cmd_from_tokens_do_4(cmd, tokens))
			break ;
	}
	ft_deque_destroy_list(tokens, delete_token_node_void);
	return (cmd);
}
