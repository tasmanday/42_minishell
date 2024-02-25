/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:53 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:55 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_1(const char *format, size_t *i, t_element *element)
{
	int	error;

	if (ft_isinstr(format[*i], "0-# +"))
		error = ft_parse_flag(format, i, element);
	else if (ft_isinstr(format[*i], "123456789"))
		error = ft_parse_minimum_field_width(format, i, element);
	else if (ft_isinstr(format[*i], "."))
		error = ft_parse_precision(format, i, element);
	else
		error = 1;
	return (error);
}

t_element	*ft_parser(const char *format, size_t *i, va_list arg_list)
{
	t_element	*element;
	int			error;

	if (format[*i] != '%')
		return (NULL);
	(*i)++;
	element = ft_element_create_empty();
	if (!element)
		return (NULL);
	error = 0;
	while (ft_isinstr(format[*i], "cspdiuxX%0-# +123456789.") && error == 0)
	{
		if (ft_isinstr(format[*i], "cspdiuxX%"))
		{
			error = ft_parse_conversion_type(format, i, element, arg_list);
			if (!error)
				return (element);
		}
		error = ft_parse_1(format, i, element);
	}
	free(element);
	return (NULL);
}
