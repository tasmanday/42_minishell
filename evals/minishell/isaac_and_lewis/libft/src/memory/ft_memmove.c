/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:09 by lxu               #+#    #+#             */
/*   Updated: 2022/01/11 03:35:28 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = dst;
	src_ptr = (char *)src;
	if (dst_ptr == src_ptr)
		return (dst);
	if (src_ptr - dst_ptr > 0)
	{
		i = 0 - 1;
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst_ptr[i] = src_ptr[i];
		}
	}
	return (dst);
}
