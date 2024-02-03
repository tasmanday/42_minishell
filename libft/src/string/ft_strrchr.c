/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:52:24 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 15:54:51 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	searches a null-terminated string for the last occurance of a given
	character.

	Inputs
	c = character (int variable as it uses ascii).
	str = string.

	Outputs
	if the character is found, returns a pointer to that character.
	if the character is not found, returns a null pointer (NULL).
*/
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
