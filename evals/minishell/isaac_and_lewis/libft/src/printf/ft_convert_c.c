/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:21:18 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 15:21:25 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_c(char c)
{
	char	*result;

	result = malloc(sizeof (*result) * 2);
	if (!result)
	{
		return (NULL);
	}
	result[0] = c;
	result[1] = '\0';
	return (result);
}
