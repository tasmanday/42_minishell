/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:28:47 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:28:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	writes the character ’c’ to the given file descriptor.

	Inputs
	c = character.
	fd = file descriptor on which to write.

	Outputs
	none.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
