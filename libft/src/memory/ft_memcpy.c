/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:30:16 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 14:02:09 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	copies a number (n) of bytes of memory from one location to another
	returns a pointer to the destination.
	temp_src & temp_dest are temporary pointers cast as unsigned chars which
	allows them to increment through the memory byte by byte.

	Inputs
	dest = pointer to destination array.
	src = pointer to the source array.
	n = number of bytes to be copied.

	Outputs
	none.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_src = (unsigned char *) src;
	temp_dest = (unsigned char *) dest;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
