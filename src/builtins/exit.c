/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:45 by sentry            #+#    #+#             */
/*   Updated: 2024/03/22 17:55:44 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;

	if (!cmd->arguments)
		exit_status = EXIT_SUCCESS;
	else
	{
		exit_status = ft_atoi((char *)cmd->arguments->data);
		if (!exit_status)
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		else if (cmd->arguments->next != NULL)
			msh_error_exit(msh, "exit\ntoo many arguments");
	}
	ft_printf("exit\n");
	exit(exit_status);
}
