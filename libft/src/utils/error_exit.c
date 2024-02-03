/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:30:25 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:04:06 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	prints an error message in red colour and exits the program.

	Inputs
	error: a string containing the error message to be printed.

	Outputs
	none.
*/
void	error_exit(const char *error)
{
	ft_printf(RED"%s\n"DEF, error);
	exit(EXIT_FAILURE);
}
