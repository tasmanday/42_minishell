/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:43:22 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 17:51:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	applies the function 'f' to each character of the given string.
	modifies the given string.

	Inputs
	str = given string.
	f = function.

	Outputs
	none.
*/
void	ft_striteri(char *str, void (*f)(size_t, char *))
{
	int	i;

	if (!str || !f)
		return (error("ft_striteri !str or !f"));
	i = 0;
	while (str[i] != '\0')
	{
		f(i, str + i);
		i++;
	}
}
