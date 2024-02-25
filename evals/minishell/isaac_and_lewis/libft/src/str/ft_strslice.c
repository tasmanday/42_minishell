/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:51:01 by lxu               #+#    #+#             */
/*   Updated: 2022/02/22 00:51:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String slicing.
 * 
 * An implementation of string slicing. As close as I can get since C doesn't
 * allow for default/empty args. And couldn't use 0 as the "blank" flag as 0 is
 * a valid slice position.
 * 
 * @param str String to slice.
 * @param left Left position to slice from (inclusive).
 * @param right Right position to slice to (exclusive).
 * @return char* Heap string of sliced result.
 */
char	*ft_strslice(const char *str, size_t left, size_t right)
{
	size_t	str_len;
	size_t	result_str_len;
	char	*result_str;
	size_t	i;

	str_len = 0;
	while (str[str_len])
		str_len++;
	if (right > str_len)
		right = str_len;
	if (left > right)
		left = right;
	result_str_len = (right - left);
	result_str = malloc(sizeof (*result_str) * (result_str_len + 1));
	if (!result_str)
		return (NULL);
	i = 0;
	while (left + i < right)
	{
		result_str[i] = str[left + i];
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}
