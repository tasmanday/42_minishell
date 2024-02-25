/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:59:31 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 21:36:12 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	allocates memory and returns a substring from the string ’str’.
	the substring begins at index ’start’ and is of maximum size ’length’.
	
	Inputs
	str = original string.
	start = start index of the substring.
	length = maximum length of substring.

	Outputs
	returns the substring or NULL if malloc fails
*/
char	*ft_substr(char const *str, size_t start, size_t length)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		start = str_len;
		length = 0;
	}
	else if (start + length > str_len)
		length = str_len - start;
	substr = (char *) malloc((length + 1) * sizeof(char));
	if (!substr)
		return (error("ft_substr malloc error"), NULL);
	i = 0;
	while (str[start + i] != '\0' && i < length)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
