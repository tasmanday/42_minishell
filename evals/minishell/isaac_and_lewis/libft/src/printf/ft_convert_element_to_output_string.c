/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_element_to_output_string.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:59:51 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 17:59:54 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_output_string	*ft_convert_element_to_output_string(t_element *element)
{
	if (element->conversion_type == 'c')
		return (ft_convert_element_c_to_output_string(element));
	if (element->conversion_type == 'd')
		return (ft_convert_element_d_to_output_string(element));
	if (element->conversion_type == 'i')
		return (ft_convert_element_i_to_output_string(element));
	if (element->conversion_type == 'p')
		return (ft_convert_element_p_to_output_string(element));
	if (element->conversion_type == '%')
		return (ft_convert_element_percent_to_output_string(element));
	if (element->conversion_type == 's')
		return (ft_convert_element_s_to_output_string(element));
	if (element->conversion_type == 'u')
		return (ft_convert_element_u_to_output_string(element));
	if (element->conversion_type == 'x')
		return (ft_convert_element_x_to_output_string(element));
	if (element->conversion_type == 'X')
		return (ft_convert_element_x_upper_to_output_string(element));
	return (NULL);
}
