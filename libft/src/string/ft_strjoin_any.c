/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:35:03 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:03:51 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the returned concatinated string.

	Summary
	concatenates multiple strings into a single string.

	Inputs
	[int] num_of_str: number of strings to concatenate.
	[...] a variable number of string arguments to concatenate.

	Outputs
	[char *] result: the concatenated string.
*/
char	*ft_strjoin_any(int num_of_str, ...)
{
	va_list		args;
	const char	*str;
	char		*result;
	char		*temp;

	if (num_of_str <= 0)
		return (NULL);
	va_start(args, num_of_str);
	result = ft_strdup("");
	while (num_of_str--)
	{
		str = va_arg(args, const char *);
		if (str)
		{
			temp = ft_strjoin(result, str);
			free(result);
			result = temp;
		}
	}
	va_end(args);
	return (result);
}
