/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:58 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 17:08:36 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

/*
 * @brief: NORM HELPERS FOR SPLIT
*/
void	split_word_do_s1(char *str, t_deque *result_pt, int *slow, int *fast)
{
	if (ft_isinstr(str[*fast], " \t\n"))
	{
		ft_deque_append(result_pt, ft_strslice(str, *slow, *fast));
		while (ft_isinstr(str[*fast], " \t\n"))
		{
			*fast = *fast + 1;
		}
		*slow = *fast;
		*fast = *fast - 1;
	}
}

void	split_word_do_s2(char str_fast, int *state)
{
	if (str_fast == '\"')
		*state = 1;
}

void	split_word_do_s3(char str_fast, int *state)
{
	if (str_fast == '\'')
		*state = 1;
}

void	split_word_init(int *slow, int *fast, int *state)
{
	*slow = 0;
	*fast = 0;
	*state = 1;
}
