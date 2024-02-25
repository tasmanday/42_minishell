/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:46 by lxu               #+#    #+#             */
/*   Updated: 2023/08/16 21:05:38 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates length of a string.
 * 
 * @param str String to measure.
 * @return size_t Number of chars in string. Not including the null terminator.
 * @return Returns 0 if string is NULL.
 */
size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (!s)
	{
		return (0);
	}
	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}
