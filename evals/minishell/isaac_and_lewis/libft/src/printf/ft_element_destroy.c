/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:17 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 18:00:18 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_element_destroy(t_element *element)
{
	if (element->content_string != NULL)
	{
		free(element->content_string);
		element->content_string = NULL;
	}
	free(element);
}
