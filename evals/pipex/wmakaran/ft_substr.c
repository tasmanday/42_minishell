/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:22:55 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/16 16:35:05 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	while (s[n])
		n++;
	if (start > n)
		output = (char *)malloc(sizeof(char));
	else if (n - start > len)
		output = (char *)malloc(sizeof(char) * (len + 1));
	else
		output = (char *)malloc(sizeof(char) * (n - start + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (start < n && s[start + i] && (i < len))
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
