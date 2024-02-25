/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:55 by lxu               #+#    #+#             */
/*   Updated: 2022/01/10 21:30:07 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	*ptr;

	ptr = (char *)s;
	c = (char)c;
	result = NULL;
	while (*ptr)
	{
		if (*ptr == c)
		{
			result = ptr;
		}
		ptr++;
	}
	if (*ptr == c)
	{
		result = ptr;
	}
	return (result);
}
