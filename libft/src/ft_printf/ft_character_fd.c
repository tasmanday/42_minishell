/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:13:54 by tday              #+#    #+#             */
/*   Updated: 2024/03/31 19:13:54 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	writes the character to the given file descriptor and increases the value
	of the character counter at &length.

	Inputs
	[int] fd: file desciptor to output to.
	[char] c: character to print.
	[int *] length: pointer to an integer that keeps count of how many
		characters have been printed.

	Outputs
	none.
 */
void	ft_character_fd(int fd, char c, int *length)
{
	write(fd, &c, 1);
	(*length)++;
}
