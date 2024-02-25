/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:11:09 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 17:17:53 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_check.h"

int	token_checks_1_check(t_token_node *token)
{
	if (token->type == OPERATOR
		&& (token->content.op == DOUBLE_PIPE
			|| token->content.op == DOUBLE_AND
			|| token->content.op == PIPE))
		return (1);
	return (0);
}

int	token_checks_1(t_token_node *token, t_token_node *next)
{
	if (token->type == OPERATOR && token->content.op == NONE_OPERATOR)
		return (print_err("msh_int: Operator token is None. Bug?\n"), 0);
	if (token_checks_1_check(token))
	{
		if (next == NULL)
			return (print_err_token_str("newline"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_PIPE)
			return (print_err_token_str("||"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_AND)
			return (print_err_token_str("&&"), 0);
		if (next->type == OPERATOR && next->content.op == PIPE)
			return (print_err_token_str("|"), 0);
		if (next->type == OPERATOR && next->content.op == RIGHT_BRACKET)
			return (print_err_token_str(")"), 0);
		if (next->type == REDIRECTION_WORD)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
		if (next->type == REDIRECTION_DELIMITER)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
	}
	return (1);
}

int	token_checks_2(t_token_node *token, t_token_node *next)
{
	if (token->type == OPERATOR && token->content.op == LEFT_BRACKET)
	{
		if (next == NULL)
			return (print_err_token_str("newline"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_PIPE)
			return (print_err_token_str("||"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_AND)
			return (print_err_token_str("&&"), 0);
		if (next->type == OPERATOR && next->content.op == PIPE)
			return (print_err_token_str("|"), 0);
		if (next->type == OPERATOR && next->content.op == RIGHT_BRACKET)
			return (print_err_token_str(")"), 0);
		if (next->type == REDIRECTION_WORD)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
		if (next->type == REDIRECTION_DELIMITER)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
	}
	return (1);
}

int	token_checks_3(t_token_node *token, t_token_node *next)
{
	if (token->type == OPERATOR && token->content.op == RIGHT_BRACKET)
	{
		if (next->type == OPERATOR && next->content.op == LEFT_BRACKET)
			return (print_err_token_str("("), 0);
		if (next->type == WORD)
			return (print_err_token_str(next->content.str), 0);
		if (next->type == REDIRECTION_WORD)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
		if (next->type == REDIRECTION_DELIMITER)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
	}
	if (token->type == WORD || token->type == REDIRECTION_WORD || \
		token->type == REDIRECTION_DELIMITER)
	{
		if (next && next->type == OPERATOR && next->content.op == LEFT_BRACKET)
			return (print_err_token_str("("), 0);
		if (next->type == REDIRECTION_WORD)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
		if (next->type == REDIRECTION_DELIMITER)
			return (print_err("msh_int: syntax error. unexpected token\n"), 0);
	}
	return (1);
}
