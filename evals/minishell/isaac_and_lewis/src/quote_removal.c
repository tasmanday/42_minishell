/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:17:55 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 10:45:22 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote_removal.h"

/*
 * NORM_HELPER for: void	remove_quotes_string(char *str)
*/
void	rqs_do_state1(char *str, size_t *i, size_t *j, int *state)
{
	if (str[*j] == '\"')
	{
		*state = 2;
		*j = *j + 1;
	}
	else if (str[*j] == '\'')
	{
		*state = 3;
		*j = *j + 1;
	}
	else
	{
		str[*i] = str[*j];
		*i = *i + 1;
		*j = *j + 1;
	}
}

/*
 * NORM_HELPER for: void	remove_quotes_string(char *str)
*/
void	rqs_do_state2(char *str, size_t *i, size_t *j, int *state)
{
	if (str[*j] == '\"')
	{
		*state = 1;
		*j = *j + 1;
	}
	else
	{
		str[*i] = str[*j];
		*i = *i + 1;
		*j = *j + 1;
	}
}

/*
 * NORM_HELPER for: void	remove_quotes_string(char *str)
*/
void	rqs_do_state3(char *str, size_t *i, size_t *j, int *state)
{
	if (str[*j] == '\'')
	{
		*state = 1;
		*j = *j + 1;
	}
	else
	{
		str[*i] = str[*j];
		*i = *i + 1;
		*j = *j + 1;
	}
}

/**
 * @brief Removes the quotes within a string while following bash rules.
 *
 * Removes quote chars \' and \" within a string. This is done in place.
 * Follows bash quoting rules (quotes within a quoted string are escaped).
 */
void	remove_quotes_string(char *str)
{
	size_t	i;
	size_t	j;
	int		state;

	i = 0;
	j = 0;
	state = 1;
	while (str[j])
	{
		if (state == 1)
		{
			rqs_do_state1(str, &i, &j, &state);
		}
		else if (state == 2)
		{
			rqs_do_state2(str, &i, &j, &state);
		}
		else if (state == 3)
		{
			rqs_do_state3(str, &i, &j, &state);
		}
		if (!str[j])
			break ;
	}
	str[i] = '\0';
}

/**
 * @brief Remove quotes from word tokens in deque of tokens.
 *
 * Operates in-place.
 *
 * @param tokens The tokens that will have quotes removed.
 */
void	remove_quotes_tokens(t_deque *tokens)
{
	t_dlist			*node;
	t_token_node	*token;

	node = tokens->head;
	while (node)
	{
		token = node->content;
		if (token->type == WORD)
		{
			remove_quotes_string(token->content.str);
		}
		node = node->next;
	}
}
