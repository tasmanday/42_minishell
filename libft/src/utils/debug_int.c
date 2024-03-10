/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:25:56 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 14:31:56 by tday             ###   ########.fr       */
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
void	debug_int(int num)
{
	ft_printf(CYAN"%i\n"DEF, num);
}
