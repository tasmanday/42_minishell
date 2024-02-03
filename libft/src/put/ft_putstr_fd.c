/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:31:54 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:31:54 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	writes the given string to the given file descriptor.

	Inputs
	str = string.
	fd = file descriptor.

	Outputs
	none.
 */
void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
