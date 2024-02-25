/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_add_padding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:34 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:35 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_helper_add_padding(t_element *element, t_output_string *os)
{
	size_t	str_len;
	size_t	padding_len;
	char	*padding_str;

	str_len = ft_output_string_len(os);
	if (str_len < element->minimum_field_width)
	{
		padding_len = element->minimum_field_width - str_len;
		padding_str = malloc(sizeof (*padding_str) * (padding_len + 1));
		if (!padding_str)
			return (1);
		padding_str[padding_len] = '\0';
		if (element->flags & negative_field_width)
			os->right_padding = ft_memset(padding_str, ' ', padding_len);
		else if (element->flags & zero_padding && \
		!((element->flags & precision_is_set) && \
		ft_isinstr(element->conversion_type, "diuxX")))
			os->leading_zeros = ft_memset(padding_str, '0', padding_len);
		else
			os->left_padding = ft_memset(padding_str, ' ', padding_len);
	}
	return (0);
}
