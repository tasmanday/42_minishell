/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:31 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:25:32 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_check.h"

int	token_checks_4_check(t_token_node *token)
{
	if (token->type == OPERATOR && \
		(token->content.op == DOUBLE_GREATER_THAN || \
		token->content.op == LESS_THAN || \
		token->content.op == GREATER_THAN))
		return (1);
	return (0);
}

//	if (next->type == WORD || next->type == REDIRECTION_DELIMITER)
//		return (print_err("msh_int: syntax error. unexpected token\n"), 0);

int	token_checks_4(t_token_node *token, t_token_node *next)
{
	if (token_checks_4_check(token))
	{
		if (next == NULL)
			return (print_err_token_str("newline"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_PIPE)
			return (print_err_token_str("||"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_AND)
			return (print_err_token_str("&&"), 0);
		if (next->type == OPERATOR && next->content.op == PIPE)
			return (print_err_token_str("|"), 0);
		if (next->type == OPERATOR && next->content.op == LEFT_BRACKET)
			return (print_err_token_str("("), 0);
		if (next->type == OPERATOR && next->content.op == RIGHT_BRACKET)
			return (print_err_token_str(")"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_LESS_THAN)
			return (print_err_token_str("<<"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_GREATER_THAN)
			return (print_err_token_str(">>"), 0);
		if (next->type == OPERATOR && next->content.op == LESS_THAN)
			return (print_err_token_str("<"), 0);
		if (next->type == OPERATOR && next->content.op == GREATER_THAN)
			return (print_err_token_str(">"), 0);
	}
	return (1);
}

//	if (next->type == WORD || next->type == REDIRECTION_WORD)
//		return (print_err("msh_int: syntax error. unexpected token\n"), 0);

int	token_checks_5(t_token_node *token, t_token_node *next)
{
	if (token->type == OPERATOR && token->content.op == DOUBLE_LESS_THAN)
	{
		if (next == NULL)
			return (print_err("msh: syntax error near unexpected `newline"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_PIPE)
			return (print_err_token_str("||"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_AND)
			return (print_err_token_str("&&"), 0);
		if (next->type == OPERATOR && next->content.op == PIPE)
			return (print_err_token_str("|"), 0);
		if (next->type == OPERATOR && next->content.op == LEFT_BRACKET)
			return (print_err_token_str("("), 0);
		if (next->type == OPERATOR && next->content.op == RIGHT_BRACKET)
			return (print_err_token_str(")"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_LESS_THAN)
			return (print_err_token_str("<<"), 0);
		if (next->type == OPERATOR && next->content.op == DOUBLE_GREATER_THAN)
			return (print_err_token_str(">>"), 0);
		if (next->type == OPERATOR && next->content.op == LESS_THAN)
			return (print_err_token_str("<"), 0);
		if (next->type == OPERATOR && next->content.op == GREATER_THAN)
			return (print_err_token_str(">"), 0);
	}
	return (1);
}
