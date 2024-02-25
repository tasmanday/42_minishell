/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:24:41 by lxu               #+#    #+#             */
/*   Updated: 2022/01/19 14:41:01 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printf_1(const char *format, size_t *i, va_list ap)
{
	t_element	*element;
	size_t		bytes_printed;

	bytes_printed = 0;
	element = ft_parser (format, i, ap);
	if (element)
	{
		bytes_printed += ft_element_print(element);
		ft_element_destroy(element);
	}
	return (bytes_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	size_t		bytes_printed;

	va_start(ap, format);
	i = 0;
	bytes_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			bytes_printed += ft_printf_1(format, &i, ap);
		}
		else
		{
			bytes_printed += write(1, &format[i], 1);
			i++;
		}
	}
	return (bytes_printed);
}
