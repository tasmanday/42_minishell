/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:49:06 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:49:06 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	writes the character to the standard output and increases the value of the
	character counter at &length.

	Inputs
	c = character.
	length = pointer to an integer that maintains the count of how many
	characters have been printed.

	Outputs
	none.
 */
void	ft_character(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}
