/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:21:23 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 11:30:03 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	check_one(t_token_node *token)
{
	if (token->type == OPERATOR
		&& (token->content.op == LESS_THAN
			|| token->content.op == DOUBLE_LESS_THAN
			|| token->content.op == GREATER_THAN
			|| token->content.op == DOUBLE_GREATER_THAN))
		return (1);
	return (0);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	check_two(t_token_node *token)
{
	if (token->type != REDIRECTION_WORD && token->type
		!= REDIRECTION_DELIMITER
		&& token->type != REDIRECTION_HEREDOC)
		return (1);
	return (0);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	check_three(t_token_node *token, t_redirection *redirection)
{
	print_err("msh_temp: syntax error: rdr op > not a word\n");
	print_err("msh_temp: syntax error near unexpected token\n");
	delete_token_node(token);
	delete_redirection(redirection);
	return (1);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
void	new_cmd_from_tokens_do_1(t_token_node *token,
		t_redirection *redirection)
{
	redirection->file_name = ft_strdup("");
	redirection->old_fd = 0;
	redirection->new_fd = dup(token->content.fd);
}

/**
 * @brief NORM_HELPER: for t_command	*new_cmd_from_tokens
*/
int	new_cmd_from_tokens_do_2(t_command *cmd, t_token_node *token,
		t_deque *tokens)
{
	t_list			*list_node;	
	t_redirection	*redirection;

	redirection = new_redirection_with_type_from_op(token->content.op);
	delete_token_node(token);
	token = ft_deque_popleft(tokens);
	if (!token && delete_redirection(redirection))
		return (1);
	if (check_two(token) && check_three(token, redirection))
		return (1);
	if (token->type == REDIRECTION_HEREDOC)
		new_cmd_from_tokens_do_1(token, redirection);
	else
		redirection->file_name = ft_strdup(token->content.str);
	delete_token_node(token);
	list_node = ft_lstnew(redirection);
	if (!list_node && delete_redirection(redirection))
		return (1);
	ft_lstadd_back(&(cmd->redirections), list_node);
	return (0);
}
