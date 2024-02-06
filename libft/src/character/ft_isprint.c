/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:54:34 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 14:55:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if the given character is a printable character.

	Inputs
	c = character (int variable as it uses ascii).

	Outputs
	true if the character is a printable character, false if it's not.
*/
bool	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (true);
	else
		return (false);
}
