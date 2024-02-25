/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:43:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 11:59:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*sav_d;
	const char	*sav_s;
	size_t		n;

	sav_d = dst;
	sav_s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*sav_d = *sav_s++;
			if (*sav_d++ == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*sav_d = '\0';
		while (*sav_s++)
			;
	}
	return (sav_s - src - 1);
}
