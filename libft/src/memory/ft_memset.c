/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:49:16 by tday              #+#    #+#             */
/*   Updated: 2024/01/13 22:49:16 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	fills a number of bytes (n) at a given memory location with a given
	character (c). returns a pointer to the start of the memory location.
	temp_str is a temporary pointer cast as an unsigned char which allows it
	to increment through the memory byte by byte.

	Inputs
	pointer = a pointer to the memory to be set.
	c = character value to set bytes to.
	n = number of bytes to be set to the character.
	
	Outputs
	none.
*/
void	*ft_memset(void *pointer, int c, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)pointer;
	while (n--)
		*temp_str++ = (unsigned char)c;
	return (pointer);
}
