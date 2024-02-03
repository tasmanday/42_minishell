/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:42:16 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 16:50:59 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	compares 2 strings up to a given number of characters. it itterates
	through and compares characters in the same position on each string.

	Inputs
	s1 = string 1.
	s2 = string 2.
	n = number of characters to compare.

	Outputs
	if the first n characters are the same, returns 0.
	if the ascii value of a character in s1 is < the char in s2, returns a
	negative value.
	if the ascii value of a character in s1 is > the char in s2, returns a
	positive value.
	if either of the strigs has less characters than 'n', it returns
	s1[i] - s2[i].
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
