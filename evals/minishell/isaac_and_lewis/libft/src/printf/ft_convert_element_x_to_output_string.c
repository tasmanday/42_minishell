/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_element_x_to_output_string.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:59:57 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 17:59:58 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_output_string	*ft_convert_element_x_to_output_string(t_element *element)
{
	t_output_string	*os;

	os = ft_output_string_create_empty();
	if (!os)
		return (NULL);
	if (ft_strncmp(element->content_string, "0", 2) == 0 && \
	element->flags & precision_is_set)
		os->value = ft_strdup("");
	else
		os->value = ft_strdup(element->content_string);
	ft_helper_add_prefix(element, os);
	ft_helper_add_precision(element, os);
	ft_helper_add_padding(element, os);
	return (os);
}
