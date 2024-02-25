/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:29:27 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 18:03:38 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_length_required(size_t n, va_list args, size_t *len)
{
	size_t	i;
	char	*s;
	size_t	total_length;
	int		all_null;

	i = 0;
	total_length = 0;
	all_null = 1;
	while (i < n)
	{
		s = va_arg(args, char *);
		if (s)
		{
			all_null = 0;
			total_length += ft_strlen(s);
		}
		i++;
	}
	if (all_null)
	{
		*len = 0;
		return (NULL);
	}
	*len = total_length;
	return (malloc(total_length + 1));
}

/**
 * @brief String concatenation.
 * 
 * An implementation of string concatenation. Returns a new heap string which is
 * the result of concatenating a bunch of arg strings. Arg number is variadic.
 *
 * If all the str pointers themselves are NULL (ie not 0 length strings but NULL
 * pointers). Then returns NULL.
 *
 * @param n The number of string to concat.
 * @param ... The strings to concat.
 * @return char* Heap string of the concatenated result.
 * @return NULL if all strings are NULL.
 */
char	*ft_strconcat(size_t n, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;
	char	*result;
	char	*s;

	va_start(args, n);
	result = malloc_length_required(n, args, &len);
	result[len] = '\0';
	va_end(args);
	if (!result)
		return (NULL);
	va_start(args, n);
	i = 0;
	while (i < len)
	{
		s = va_arg(args, char *);
		if (s)
		{
			i += ft_strlcpy(&(result[i]), s, ft_strlen(s) + 1);
		}
	}
	va_end(args);
	return (result);
}
