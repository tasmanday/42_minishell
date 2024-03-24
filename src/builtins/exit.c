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

void	ft_exit(t_msh	*msh)
{
	t_cmd	*cmd_struct;
	int		exit_status;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
		exit_status = EXIT_SUCCESS;
	else
	{
		exit_status = ft_atoi((char *)cmd_struct->arguments->data);
		if (!exit_status)
			error_exit("exit\nvalid numeric argument required");
		else if (cmd_struct->arguments->next != NULL)
			error_exit("exit\ntoo many arguments");
	}
	printf("exit\n");
	exit(exit_status);
}
