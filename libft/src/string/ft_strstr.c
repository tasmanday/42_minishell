/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:29 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 16:06:56 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	searches for the first occurrence of a substring within a string.

	Inputs
	str = a pointer to the string in which to search for the substring.
	to_find = a pointer to the substring to search for.

	Outputs
	a pointer to the beginning of the substring if found,
	or a null pointer if the substring is not present.
*/
char	*ft_strstr(char *str, char *to_find)
{
	char	*temp_str;
	char	*temp_to_find;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		temp_str = str;
		temp_to_find = to_find;
		while (*str++ == *to_find++)
		{
			if (*to_find == '\0')
				return (temp_str);
		}
		str = temp_str++;
		to_find = temp_to_find;
	}
	return (NULL);
}
