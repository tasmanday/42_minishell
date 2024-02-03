/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:59:31 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 17:07:57 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	allocates memory and returns a substring from the string ’str’.
	the substring begins at index ’start’ and is of maximum size ’sub_len’.
	
	Inputs
	str = original string.
	start = start index of the substring.
	sub_len = maximum length of substring.

	Outputs
	returns the substring or NULL if malloc fails
*/
char	*ft_substr(char const *str, unsigned int start, size_t sub_len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		start = str_len;
		sub_len = 0;
	}
	else if (start + sub_len > str_len)
		sub_len = str_len - start;
	substr = (char *) malloc((sub_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (str[start + i] != '\0' && i < sub_len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
