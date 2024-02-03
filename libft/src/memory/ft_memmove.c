/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:16:38 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 13:21:43 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	copies a block of memory from one location to another, returns a pointer
	to the destination. handles overlapping of source and destination by
	copying original source bytes before they are overwritten.
	temp_src & temp_dest = temporary pointers cast as unsigned chars which
	allows them to increment through the memory byte by byte.

	Inputs
	dest = pointer to destination array.
	src = pointer to the source array.
	n = number of bytes to be copied.

	Outputs
	none.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	temp_dest = dest;
	temp_src = src;
	if (temp_dest == temp_src)
		return (dest);
	else if (dest > src)
		while (n--)
			temp_dest[n] = temp_src[n];
	else
		while (n--)
			*temp_dest++ = *temp_src++;
	return (dest);
}
