/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_create_empty.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:14 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_element_create_empty(void)
{
	t_element	*element;

	element = malloc(sizeof(*element) * 1);
	if (!element)
	{
		return (NULL);
	}
	element->flags = 0;
	element->conversion_type = '\0';
	element->precision = 0;
	element->minimum_field_width = 0;
	element->content_string = NULL;
	return (element);
}
