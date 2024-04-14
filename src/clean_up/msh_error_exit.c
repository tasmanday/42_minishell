/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:52:11 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:01:12 by atang            ###   ########.fr       */
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
/* void	msh_error_exit(t_msh *msh, char *error_message)
{
	free_everything(msh);
	error_exit(error_message);
} */

void	msh_error_exit(t_msh *msh, char *error_message)
{
	int		exit_status;

	exit_status = msh->last_exit_status;
	if (exit_status == 0)
		exit_status = EXIT_FAILURE;
	ft_printf_fd(2, RED "%s\n" DEF, error_message);
	free_everything(msh);
	exit(exit_status);
}
