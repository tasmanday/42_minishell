/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:11:47 by tday              #+#    #+#             */
/*   Updated: 2024/03/31 20:11:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	prints the given string to the given file descriptor using ft_character
	so that the value at length is also increased.
	prints (null) if the string doesn't exist.

	Inputs
	[int] fd: file desciptor to output to.
	[char *] s: a string of characters.
	[int *] length: pointer to an integer that keeps count of how many
		characters have been printed.

	Outputs
	none.
 */
void	ft_string_fd(int fd, char *s, int *length)
{
	size_t	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		(*length) += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_character_fd(fd, s[i], length);
		i++;
	}
}
