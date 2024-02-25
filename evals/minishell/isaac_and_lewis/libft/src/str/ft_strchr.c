/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:37 by lxu               #+#    #+#             */
/*   Updated: 2022/01/10 21:23:00 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *)s;
	c = (char)c;
	while (*result && *result != c)
	{
		result++;
	}
	if (*result == c)
	{
		return (result);
	}
	return (NULL);
}
