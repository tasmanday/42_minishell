/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_element_c_to_output_string.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:59:14 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 17:59:18 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_output_string	*ft_convert_element_c_to_output_string(t_element *element)
{
	t_output_string	*os;
	char			*value_string;

	os = ft_output_string_create_empty();
	if (!os)
		return (NULL);
	value_string = malloc(sizeof (*value_string) * 2);
	if (!value_string)
		return (NULL);
	os->value = ft_memcpy(value_string, element->content_string, 2);
	os->value_override_bytes_to_print = 1;
	ft_helper_add_padding(element, os);
	return (os);
}
