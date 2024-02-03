/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:16:21 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:16:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	writes the given string to the standard output (terminal).

	Inputs
	str = string.

	Outputs
	none.
 */
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
