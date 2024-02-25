/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:29:45 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 00:29:49 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_conversion_type(const char *format, size_t *i, \
t_element *element, va_list arg_list)
{
	if (format[*i] == 'c')
		element->content_string = ft_convert_c(va_arg(arg_list, int));
	else if (format[*i] == 'd')
		element->content_string = ft_convert_d(va_arg(arg_list, int));
	else if (format[*i] == 'i')
		element->content_string = ft_convert_i(va_arg(arg_list, int));
	else if (format[*i] == 'p')
		element->content_string = ft_convert_p(va_arg(arg_list, void *));
	else if (format[*i] == '%')
		element->content_string = ft_convert_percent();
	else if (format[*i] == 's')
		element->content_string = ft_convert_s(va_arg(arg_list, char *));
	else if (format[*i] == 'u')
		element->content_string = ft_convert_u(va_arg(arg_list, unsigned int));
	else if (format[*i] == 'x')
		element->content_string = ft_convert_x(va_arg(arg_list, int));
	else if (format[*i] == 'X')
		element->content_string = ft_convert_x_upper(va_arg(arg_list, int));
	else
		return (1);
	element->conversion_type = format[*i];
	(*i)++;
	return (0);
}
