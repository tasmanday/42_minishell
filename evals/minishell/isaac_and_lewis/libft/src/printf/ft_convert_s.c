/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:51 by lxu               #+#    #+#             */
/*   Updated: 2022/01/19 14:26:42 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_s(char *str)
{
	char	*result;

	if (!str)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(str);
	return (result);
}
