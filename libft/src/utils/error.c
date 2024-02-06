/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c   	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:02:22 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:08:05 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	prints an error message in red colour.

	Inputs
	error: a string containing the error message to be printed.

	Outputs
	none.
*/
void	error(const char *error)
{
	ft_printf(RED"%s\n"DEF, error);
}
