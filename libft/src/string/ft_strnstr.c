/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:08:31 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 16:12:41 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks the first n characters of a string to find the first occurrence of
	a substring.

	Inputs
	haystack = string to be searched.
	needle = substring that the function is searching for.
	n = number of characters to check.

	Outputs
	returns a pointer to the first occurance of the substring or NULL if the
	needle substring is not found in the first n characters of the haystack
	string.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (needle_len > n)
		return (NULL);
	while (*haystack != '\0' && n >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
