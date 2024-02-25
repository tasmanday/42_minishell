/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string_create_empty.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:40 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:41 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_output_string	*ft_output_string_create_empty(void)
{
	t_output_string	*output_string;

	output_string = malloc(sizeof(*output_string) * 1);
	if (!output_string)
	{
		return (NULL);
	}
	output_string->left_padding = NULL;
	output_string->prefix = NULL;
	output_string->leading_zeros = NULL;
	output_string->value = NULL;
	output_string->value_override_bytes_to_print = 0;
	output_string->right_padding = NULL;
	return (output_string);
}
