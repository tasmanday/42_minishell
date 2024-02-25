/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:41 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:42 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_output_string_destroy(t_output_string *output_string)
{
	if (output_string->left_padding)
		free(output_string->left_padding);
	if (output_string->prefix)
		free(output_string->prefix);
	if (output_string->leading_zeros)
		free(output_string->leading_zeros);
	if (output_string->value)
		free(output_string->value);
	if (output_string->right_padding)
		free(output_string->right_padding);
	free(output_string);
}
