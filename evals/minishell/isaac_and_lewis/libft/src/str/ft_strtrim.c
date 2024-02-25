/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:56 by lxu               #+#    #+#             */
/*   Updated: 2022/01/10 21:32:42 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isinstr(s1[start], set))
		start++;
	while (end > start && ft_isinstr(s1[end - 1], set))
		end--;
	result = malloc(sizeof (*result) * (end - start + 1));
	if (!result)
		return (result);
	i = 0;
	while (i + start < end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
