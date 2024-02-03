/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:56:43 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 15:01:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	concatenates two strings. src is appended to the end of dest.

	Inputs
	dest = a pointer to the destination string where the concatenated string
	will be stored.
	src = a pointer to the source string that will be appended to the
	destination string.

	Outputs
	temp_dest = a pointer to the original dest string.
*/
char	*ft_strcat(char *dest, char *src)
{
	char	*temp_dest;

	temp_dest = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (temp_dest);
}
