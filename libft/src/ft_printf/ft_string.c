/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:10:40 by tday              #+#    #+#             */
/*   Updated: 2024/01/15 00:10:40 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	prints the given string to the standard output using ft_character so that
	the value at length is also increased.
	prints (null) if the string doesn't exist.

	Inputs
	s = a string of characters.
	length = pointer to an integer that maintains the count of how many
	characters have been printed.

	Outputs
	none.
 */
void	ft_string(char *s, int *length)
{
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_character(s[i], length);
		i++;
	}
}
