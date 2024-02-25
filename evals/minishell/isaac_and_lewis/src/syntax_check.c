/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:31 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 16:37:20 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_check.h"

int	first_node_valid(t_dlist	*node)
{
	t_token_node	*token;

	token = node->content;
	if (!token)
	{
		return (print_err("msh_internal: Op token node is NULL\n"), 0);
	}
	if (token->type == OPERATOR && token->content.op == DOUBLE_PIPE)
	{
		return (print_err_token_str("||"), 0);
	}
	if (token->type == OPERATOR && token->content.op == DOUBLE_AND)
	{
		return (print_err_token_str("&&"), 0);
	}
	if (token->type == OPERATOR && token->content.op == PIPE)
	{
		return (print_err_token_str("|"), 0);
	}
	if (token->type == OPERATOR && token->content.op == RIGHT_BRACKET)
	{
		return (print_err_token_str(")"), 0);
	}
	return (1);
}

int	at_end_with_appropriate_token(t_dlist *node)
{
	t_token_node	*token;

	if (node->next != NULL)
	{
		return (0);
	}
	token = node->content;
	if (token->type == OPERATOR && token->content.op == RIGHT_BRACKET)
	{
		return (1);
	}
	if (token->type == WORD || \
	token->type == REDIRECTION_WORD || \
	token->type == REDIRECTION_DELIMITER)
	{
		return (1);
	}
	return (0);
}

int	syntax_is_valid_do(t_dlist *node, int *open_bracket_count, int *state)
{
	t_token_node	*token;
	t_token_node	*next_token;

	token = node->content;
	next_token = NULL;
	if (node->next)
	{
		next_token = node->next->content;
	}
	if (bracket_checks(token, open_bracket_count, state) == 0 || \
		token_checks_1(token, next_token) == 0 || \
		token_checks_2(token, next_token) == 0 || \
		token_checks_3(token, next_token) == 0 || \
		token_checks_4(token, next_token) == 0 || \
		token_checks_5(token, next_token) == 0)
	{
		return (0);
	}
	return (1);
}

/**
 * @brief Checks for syntax errors in a deque of tokens
 *
 * Walks through a deque of tokens and checks for syntax errors. Errors that are
 * checked are:
 *     - Negative bracket count at any stage.
 *     - Operator following operator that is invalid.
 */
int	syntax_is_valid(t_deque tokens)
{
	t_dlist			*node;
	int				open_bracket_count;
	int				state;

	open_bracket_count = 0;
	state = 1;
	node = tokens.head;
	if (node && first_node_valid(node) == 0)
	{
		return (0);
	}
	while (node)
	{
		update_bracket_count(node, &open_bracket_count, &state);
		if (at_end_with_appropriate_token(node))
			break ;
		if (syntax_is_valid_do(node, &open_bracket_count, &state) == 0)
			return (0);
		node = node->next;
	}
	if (open_bracket_count > 0)
		return (\
		print_err("msh_warn: unclosed parenthesis '(' ')' not supported\n"), 0);
	return (1);
}
