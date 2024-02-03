/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:07:03 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 14:01:41 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	fills a number of bytes (n) at a given memory location with 0 ('\0').

	Inputs
	pointer = a pointer to the memory to be set.
	n = number of bytes to be set to the character.

	Outputs
	none
*/
void	ft_bzero(void *pointer, size_t n)
{
	while (n--)
		*(char *)pointer++ = '\0';
}
