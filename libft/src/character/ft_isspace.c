/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:56:41 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 14:57:34 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if the given character is a white space character.

	Inputs
	c = character (int variable as it uses ascii).

	Outputs
	true if the character is a white space character, false if it's not.
*/
bool	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (true);
	else
		return (false);
}
