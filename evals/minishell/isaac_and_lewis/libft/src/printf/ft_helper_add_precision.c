/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_add_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:36 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 19:26:51 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_helper_add_precision(t_element *element, t_output_string *os)
{
	size_t	val_len;
	size_t	num_zeros;

	if (ft_isinstr(element->conversion_type, "diuxXp"))
	{
		val_len = ft_strlen(os->value);
		if (val_len < element->precision)
		{
			num_zeros = element->precision - val_len;
			os->leading_zeros = malloc(sizeof *(os->leading_zeros) * \
					(num_zeros + 1));
			if (!(os->leading_zeros))
				return (1);
			os->leading_zeros = ft_memset(os->leading_zeros, '0', num_zeros);
			(os->leading_zeros)[num_zeros] = '\0';
		}
	}
	else if (element->conversion_type == 's')
	{
		if (ft_strlen(os->value) > element->precision && \
		element->flags & precision_is_set)
			os->value[element->precision] = '\0';
	}
	return (0);
}
