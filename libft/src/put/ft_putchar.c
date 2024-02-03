/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:09:59 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:09:59 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	writes the given character ’c’ to the standard output (terminal).

	Inputs
	c = character.

	Outputs
	none.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
