/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:52:11 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 21:21:51 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees all allocated memory and exits the program while printing an error
	message to the terminal.

	Inputs
	[t_msh *] msh: the main structure.
	[char *] error_message: the error message to be printed to the terminal.

	Outputs
	none.
*/
void	msh_error_exit(t_msh *msh, char *error_message)
{
	free_everything(msh);
	error_exit(error_message);
}
