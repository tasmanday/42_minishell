/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_add_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:37 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:39 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_helper_add_prefix(t_element *element, t_output_string *os)
{
	if (ft_isinstr(element->conversion_type, "di"))
	{
		if (element->content_string[0] == '-')
			os->prefix = ft_strdup("-");
		else if (element->flags & prepend_sign)
			os->prefix = ft_strdup("+");
		else if (element->flags & prepend_negative_or_space)
			os->prefix = ft_strdup(" ");
	}
	if (element->conversion_type == 'x' && element->flags & alternate_form && \
	os->value)
	{
		if (ft_strncmp(os->value, "0", 2) != 0)
			os->prefix = ft_strdup("0x");
	}
	if (element->conversion_type == 'X' && element->flags & alternate_form && \
	os->value)
	{
		if (ft_strncmp(os->value, "0", 2) != 0)
			os->prefix = ft_strdup("0X");
	}
	return (0);
}
