/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:19 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:32 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_element_print(t_element *element)
{
	t_output_string	*output_string;
	size_t			bytes_printed;

	output_string = ft_convert_element_to_output_string(element);
	if (!output_string)
	{
		return (0);
	}
	bytes_printed = ft_output_string_print(output_string);
	ft_output_string_destroy(output_string);
	return (bytes_printed);
}
