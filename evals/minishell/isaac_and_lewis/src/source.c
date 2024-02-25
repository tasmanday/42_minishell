/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:34:33 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:38:27 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

// FSM
// 1: normal
// 2: inside dquote
// 3: inside squote
char	*take_word(t_source *src)
{
	size_t	end;
	char	*result;
	int		state;

	state = 1;
	end = src->pos;
	result = NULL;
	if (src->buff[end] == '\0')
		return (NULL);
	while (1)
	{
		if (src->buff[end] == '\0')
			return (take_word_do1(result, src, end));
		if (state == 1)
		{
			if (take_word_check1(src, end))
				return (take_word_do1(result, src, end));
			take_word_do2(src, &state, &end);
		}
		else if (state == 2)
			take_word_do_state2(src, &state, &end);
		else if (state == 3)
			take_word_do_state3(src, &state, &end);
	}
}

void	deit_oq_set_state(int *open_temp_quotes, int *state, int state_set)
{
	*open_temp_quotes = *open_temp_quotes - 1;
	*state = state_set;
}

void	quotes_valid_do_state1(char str_i, int *open_double_quotes,
		int *open_single_quotes, int *state)
{
	if (str_i == '\"')
	{
		*open_double_quotes = *open_double_quotes + 1;
		*state = 2;
	}
	if (str_i == '\'')
	{
		*open_single_quotes = *open_single_quotes + 1;
		*state = 3;
	}
}

void	quotes_valid_init(int *open_single_quotes, int *open_double_quotes,
		int *state, size_t *i)
{
	*open_single_quotes = 0;
	*open_double_quotes = 0;
	*state = 1;
	*i = -1;
}

// FSM
// 1: normal
// 2: inside dquote
// 3: inside squote
int	quotes_valid(char *str)
{
	int		osq;
	int		odq;
	int		state;
	size_t	i;

	quotes_valid_init(&osq, &odq, &state, &i);
	while (str[++i])
	{
		if (state == 1)
			quotes_valid_do_state1(str[i], &odq, &osq, &state);
		else if (state == 2)
		{
			if (str[i] == '\"')
				deit_oq_set_state(&odq, &state, 1);
		}
		else if (state == 3 && (str[i] == '\''))
			deit_oq_set_state(&osq, &state, 1);
		if (odq < 0 || osq < 0)
			return (0);
	}
	if (odq > 0 || osq > 0)
		return (0);
	return (1);
}
