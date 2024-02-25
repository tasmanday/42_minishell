/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:58:14 by lxu               #+#    #+#             */
/*   Updated: 2023/09/25 14:04:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	set_nulls(int *a, t_dlist **b, t_dlist **c, t_dlist **d)
{
	*a = 0;
	*b = NULL;
	*c = NULL;
	*d = NULL;
}

int	bracket_check(t_dlist *node, int open_bracket_count, t_dlist **last_bracket)
{
	t_token_node	*token;

	token = node->content;
	if (token->type == OPERATOR && token->content.op == LEFT_BRACKET)
	{
		open_bracket_count++;
	}
	if (token->type == OPERATOR && token->content.op == RIGHT_BRACKET)
	{
		open_bracket_count--;
		*last_bracket = node;
	}
	return (open_bracket_count);
}

void	update_first_node(t_dlist *node, int open_bracket_count,
	t_dlist **first_and_or_node, t_dlist **first_pipe_node)
{
	t_token_node	*token;

	if (open_bracket_count != 0)
	{
		return ;
	}
	token = node->content;
	if (*first_and_or_node == NULL && token->type == OPERATOR && \
		(token->content.op == DOUBLE_AND || \
		token->content.op == DOUBLE_PIPE))
	{
		*first_and_or_node = node;
	}
	if (*first_pipe_node == NULL && token->type == OPERATOR && \
		token->content.op == PIPE)
	{
		*first_pipe_node = node;
	}
}

/**
 * @brief Returns the next location for tokens to be split on.
 *
 * Searches through a list of tokens to figure out the next location to split
 * on. The splitting order is dictated by 3 things (as inferred from the bash
 * docs)
 *
 * - If a operatior is inside brackets it is "ignored". It will only be able
 *       to split on this location once the brackets are unwrapped.
 * - If there is any && or || operators, split on the last one of these.
 * - Split on the last |, but only if there are no remaining && or || operators.
 *
 * @param tokens The deque of tokens to split.
 * @return The dlist node to be split on next.
 *         NULL if there is no remaining node to be split on (No &&, ||, | left)
 *         NULL if there is an invalid number of brackets. Although this clashes
 *             with the above. Maybe need to communicate this another way?
 */
t_dlist	*tokens_next_split_location(t_deque tokens)
{
	int				open_brackets;
	t_dlist			*node;
	t_dlist			*first_and_or;
	t_dlist			*first_pipe;
	t_dlist			*last_bracket;

	node = tokens.head;
	set_nulls(&open_brackets, &first_and_or, &first_pipe, &last_bracket);
	while (node)
	{
		open_brackets = bracket_check(node, open_brackets, &last_bracket);
		if (open_brackets < 0)
			return (print_err("msh_temp: Parse Error.\n"), NULL);
		update_first_node(node, open_brackets, &first_and_or, &first_pipe);
		node = node->next;
	}
	if (first_and_or)
		return (first_and_or);
	if (first_pipe)
		return (first_pipe);
	if (last_bracket)
		return (last_bracket);
	return (NULL);
}
