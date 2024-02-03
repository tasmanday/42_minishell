/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:02:11 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 15:07:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
Summary
	concatenates 2 strings together and returns the lenght of the sum of the
	strings.
	if the destination string is >= the destination buffer,
	returns length of the source string + length of the destination buffer.
	else if the source string is < the free space in the destination buffer,
	copies the source string after the destination string and adds a
	null-terminator.
	else if the source string is > the free space in the destination buffer
	copies as much of the source string that will fit and adds a
	null-terminator.

	Inputs
	dest = destination string.
	src = source string.
	dest_buff_len = total lenth of the destination buffer.

	Outputs
	returns the length of the concatenated string (src_len + dest_len).
	src_len = length of the source string.
	dest_len = length of the destination string.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t dest_buff_len)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= dest_buff_len)
		return (src_len + dest_buff_len);
	if (src_len < dest_buff_len - dest_len)
		ft_memmove(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memmove(dest + dest_len, src, dest_buff_len - (dest_len + 1));
		dest[dest_buff_len - 1] = '\0';
	}
	return (dest_len + src_len);
}
