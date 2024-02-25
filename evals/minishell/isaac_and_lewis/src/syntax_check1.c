/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:31 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 16:37:58 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_check.h"

void	print_err_token_str(char *token_str)
{
	print_err("msh: syntax error near unexpected token `%s'\n", token_str);
}

void	update_bracket_count(t_dlist *node, int *open_bracket_count, int *state)
{
	t_token_node	*token;

	token = node->content;
	if (token->type == OPERATOR && token->content.op == LEFT_BRACKET)
		*open_bracket_count += 1;
	if (token->type == OPERATOR && token->content.op == RIGHT_BRACKET)
	{
		*open_bracket_count -= 1;
		*state = 2;
	}
}

int	bracket_checks(t_token_node *token, int *open_bracket_count, int *state)
{
	if (*open_bracket_count < 0)
		return (print_err_token_str(")"), 0);
	if (*state == 2)
	{
		if (token->type == OPERATOR && (
				token->content.op == DOUBLE_PIPE \
			|| token->content.op == DOUBLE_AND \
			|| token->content.op == PIPE))
		{
			*state = 1;
		}
		if (token->type == OPERATOR && token->content.op == LEFT_BRACKET)
			return (print_err_token_str("("), 0);
		if (token->type == WORD)
			return (print_err_token_str(token->content.str), 0);
	}
	return (1);
}
