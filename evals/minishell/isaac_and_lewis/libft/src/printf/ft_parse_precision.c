/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:29:53 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 00:29:54 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_precision(const char *format, size_t *i, \
t_element *element)
{
	if (format[*i] != '.')
		return (1);
	(*i)++;
	element->flags = element->flags | precision_is_set;
	element->precision = 0;
	while (ft_isdigit(format[*i]))
	{
		element->precision *= 10;
		element->precision += format[*i];
		element->precision -= '0';
		(*i)++;
	}
	return (0);
}
