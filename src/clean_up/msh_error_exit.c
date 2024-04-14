/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:52:11 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 17:56:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees all allocated memory and exits the program while printing an error
	message to the terminal.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.
	[char *] error_message: the error message to be displayed.

	Outputs
	none. exits the program with the appropriate exit status.
*/
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
