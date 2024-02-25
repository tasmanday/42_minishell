/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:55:30 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 21:52:55 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	allocates memory and copies a source string to a destination string, the 
	source string must be null-terminated.

	Inputs
	src = source string.

	Outputs
	dest = destination string.
*/
char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
	{
		error("ft_strdup malloc error");
		return (NULL);
	}
	dest = ft_memmove(dest, src, len + 1);
	return (dest);
}
