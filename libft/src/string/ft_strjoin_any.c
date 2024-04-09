/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:35:03 by tday              #+#    #+#             */
/*   Updated: 2024/04/09 20:35:03 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* char	*ft_strjoin_any(int num_of_str, ...)
{
	va_list		args;
	int			length;
	int			i;
	const char	*str;
	char		*result;
	
	length = 0;
	i = num_of_str;
	va_start(args, num_of_str);
	while (i-- > 0)
	{
		str = va_arg(args, const char *);
		if (str)
			length += ft_strlen(str);
	}
	va_end(args);
	result = (char *)safe_malloc(length + 1, "ft_strjoin_any malloc error");
	i = 0;
	va_start(args, num_of_str);
	while (num_of_str-- > 0)
	{
		str = va_arg(args, const char *);
		if (str)
		{
			length = ft_strlen(str);
			ft_memcpy(&result[i], str, length);
			i += length;
		}
	}
	va_end(args);
	result[i] = '\0';
	return (result);
} */

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
