/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:39:10 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 14:42:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

/**
 * @brief NORM_HELPERS: for char	*take_word(t_source *src)
*/
char	*take_word_do1(char *result, t_source *src, size_t end)
{
	result = ft_strslice(src->buff, src->pos, end);
	src->pos = end;
	return (result);
}

void	take_word_do2(t_source *src, int *state, size_t *end)
{
	if (src->buff[*end] == '\"')
		*state = 2;
	if (src->buff[*end] == '\'')
		*state = 3;
	*end = *end + 1;
}

void	take_word_do_state2(t_source *src, int *state, size_t *end)
{
	if (src->buff[*end] == '\"')
		*state = 1;
	*end = *end + 1;
}

void	take_word_do_state3(t_source *src, int *state, size_t *end)
{
	if (src->buff[*end] == '\'')
		*state = 1;
	*end = *end + 1;
}

int	take_word_check1(t_source *src, size_t end)
{
	if ((ft_isinstr(src->buff[end], " \t\n"))
		|| (src->buff[end] == '&' && src->buff[end + 1] == '&')
		|| (ft_isinstr(src->buff[end], "|()<>")))
		return (1);
	return (0);
}
