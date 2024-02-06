/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:07:44 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 22:13:16 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	allocates memory and converts the given integer to a string of characters.

	Inputs
	n = the given integer.

	Outputs
	a pointer to the string.
*/
char	*ft_itoa(long long n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_get_len_int(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (error("ft_itoa malloc error"), NULL);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (len-- && n)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
