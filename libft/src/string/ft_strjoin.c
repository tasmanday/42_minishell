/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:09:37 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 18:20:09 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	allocates memory and returns a new string, which is the result of the
	concatenation of s1 and s2.

	Inputs
	s1 = string 1.
	s2 = string 2.

	Outputs
	result = joined strings.
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (error("ft_strjoin malloc error"), NULL);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2 + 1);
	return (result);
}
