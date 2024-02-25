/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minimum_field_width.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:29:51 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 00:29:52 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_minimum_field_width(const char *format, size_t *i, \
t_element *element)
{
	element->minimum_field_width = 0;
	while (ft_isdigit(format[*i]))
	{
		element->minimum_field_width *= 10;
		element->minimum_field_width += format[*i];
		element->minimum_field_width -= '0';
		(*i)++;
	}
	return (0);
}
