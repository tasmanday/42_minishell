/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:48:50 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 14:53:13 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	copies a source string into a destination buffer of a certain size. if the
	source is longer than the destination it will shorten it so that it fits.
	returns the length of the source string.
	len = number of characters to be copied from src to dest.

	Inputs
	dest = destination buffer.
	src = source string.
	dest_len = length of destination buffer.

	Outputs
	src len = length of the source string.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_len)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	if (dest_len == 0)
		return (src_len);
	else if (src_len >= dest_len)
		len = dest_len - 1;
	else
		len = src_len;
	ft_memmove(dest, src, len);
	dest[len] = '\0';
	return (src_len);
}
