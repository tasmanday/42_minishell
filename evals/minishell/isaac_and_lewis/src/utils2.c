/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:38:19 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_str(char *str, size_t *i)
{
	write(2, str, ft_strlen(str));
	*i += 1;
}

void	print_int(int val, size_t *i)
{
	char	*s;

	s = ft_itoa(val);
	write(2, s, ft_strlen(s));
	free(s);
	*i += 1;
}

void	print_err(char *fmt, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 's')
				print_str(va_arg(args, char *), &i);
			if (fmt[i] == 'd')
				print_int(va_arg(args, int), &i);
		}
		else
		{
			write(2, &fmt[i], 1);
			i++;
		}
	}
	va_end(args);
}

/**
 * @brief get the number of nodes in our deque
 *
 * @param tokens The tokens array for comparison.
 * @return the size of the deque.
 */
int	get_deque_size(t_deque *tokens)
{
	t_dlist	*node;
	int		count;

	node = tokens->head;
	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}
