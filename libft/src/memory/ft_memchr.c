/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:29:03 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 13:37:43 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	searches for the first occurrence of a specific character in a block of
	memory, returns a pointer to the matching byte or NULL if the character
	does not occur in the given number of bytes after the pointer.
	temp_str is a temporary pointer cast as an unsigned char which allows it
	to increment through the memory byte by byte.

	Inputs
	ptr = a pointer to the memory location.
	c = character (int variable as it uses ascii).
	n = number of bytes to check.

	Outputs
	none.
*/
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)ptr;
	while (n--)
	{
		if (*temp_str == (unsigned char)c)
			return (temp_str);
		temp_str++;
	}
	return (NULL);
}
