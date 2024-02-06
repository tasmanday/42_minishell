/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:38:52 by tday              #+#    #+#             */
/*   Updated: 2024/02/06 18:38:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	prints an debug message in red colour.

	Inputs
	str: a string containing the debug message to be printed.

	Outputs
	none.
*/
void	debug(const char *str)
{
	ft_printf(CYAN"%s\n"DEF, str);
}
