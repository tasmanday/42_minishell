/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:16 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 12:56:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	searches for the first occurrence of a character in a string and returns
	a pointer to that character.

	Inputs
	str = a pointer to the string to be searched.
	c = the character to be found in the string.

	Outputs
	if the character is found, returns a pointer to that character.
	if the character is NULL, returns a pointer to the null-terminator at the
	end of the string.
	if the character is not found, returns a null pointer (NULL).
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (0);
}
