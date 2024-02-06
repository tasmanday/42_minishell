/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:52:32 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 14:53:24 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if the given character is an ASCII character.

	Inputs
	c = character (int variable as it uses ascii).

	Outputs
	true if the character is ASCII, false if it's not.
*/
bool	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (true);
	else
		return (false);
}
