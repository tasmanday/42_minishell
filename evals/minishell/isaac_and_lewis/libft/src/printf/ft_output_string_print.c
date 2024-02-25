/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:47 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:51 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	putstr_ret_bytes(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

size_t	ft_output_string_print_1(t_output_string *output_string)
{
	size_t	bytes_printed;

	bytes_printed = 0;
	if (output_string->left_padding)
		bytes_printed += putstr_ret_bytes(output_string->left_padding, 1);
	if (output_string->prefix)
		bytes_printed += putstr_ret_bytes(output_string->prefix, 1);
	if (output_string->leading_zeros)
		bytes_printed += putstr_ret_bytes(output_string->leading_zeros, 1);
	return (bytes_printed);
}

size_t	ft_output_string_print(t_output_string *output_string)
{
	size_t	bytes_printed;
	size_t	i;

	bytes_printed = ft_output_string_print_1(output_string);
	if (output_string->value)
	{
		if (output_string->value_override_bytes_to_print)
		{
			i = 0;
			while (i < output_string->value_override_bytes_to_print)
			{
				ft_putchar_fd((output_string->value)[i], 1);
				bytes_printed++;
				i++;
			}
		}
		else
			bytes_printed += putstr_ret_bytes(output_string->value, 1);
	}
	if (output_string->right_padding)
		bytes_printed += putstr_ret_bytes(output_string->right_padding, 1);
	return (bytes_printed);
}
