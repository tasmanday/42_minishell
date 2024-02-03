/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:39:02 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 13:45:53 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	compares 2 blocks of memory up to a given number of bytes or the first
	different byte. If all bytes are the same, returns 0.
	if the ascii value of a character in s1 is < the char in s2,
	returns a negative value.
	if the ascii value of a character in s1 is > the char in s2,
	returns a positive value.
	temp_s1 & temp_s2 = temporary pointers cast as unsigned chars which
	allows them to increment through the memory byte by byte.

	Inputs
	s1 = memory location 1.
	s2 = memory location 2.
	n = number of characters to compare.

	Outputs
	an integer, 0 if all bytes are the same, !0 if at least one of the
	compared bytes is different.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		temp_s1++;
		temp_s2++;
	}
	return (0);
}
