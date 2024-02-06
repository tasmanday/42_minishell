/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:54:58 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 09:12:32 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if a given character c is present in the given character set.

	Inputs
	c = a character to be checked if it is in the set.
	set = a set of characters to be checked against.

	Outputs
	1 (true) if c is in set.
	0 (false) if c is not in set.
*/
static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
	Summary
	allocates memory and returns a copy of s1 with the characters specified in
	set removed from the beginning and the end of the string.

	Inputs
	s1 = string to be trimmed.
	set = set of characters to trim.

	Outputs
	trimmed_str = the trimmed version of the s1 string with the characters in
	set removed form the start and the end.
*/
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (error("ft_strtrim malloc error"), NULL);
	trimmed_str = ft_memmove(trimmed_str, s1 + start, end - start);
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}
