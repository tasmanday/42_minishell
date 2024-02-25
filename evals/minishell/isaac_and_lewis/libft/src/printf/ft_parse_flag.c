/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:29:50 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 00:29:51 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_flag(const char *format, size_t *i, t_element *element)
{
	if (format[*i] == '0')
		element->flags = element->flags | zero_padding;
	else if (format[*i] == '-')
		element->flags = element->flags | negative_field_width;
	else if (format[*i] == '#')
		element->flags = element->flags | alternate_form;
	else if (format[*i] == ' ')
		element->flags = element->flags | prepend_negative_or_space;
	else if (format[*i] == '+')
		element->flags = element->flags | prepend_sign;
	else
		return (1);
	(*i)++;
	return (0);
}
