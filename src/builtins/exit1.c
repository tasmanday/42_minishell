/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:45 by sentry            #+#    #+#             */
/*   Updated: 2024/04/13 18:11:10 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_exit(t_msh *msh, t_cmd *cmd)
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
} */

static int	is_valid_numeric(const char *arg)
{
	if (arg == NULL || *arg == '\0')
	{
		return (0);
	}
	if (*arg == '+' || *arg == '-')
	{
		arg++;
	}
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
		{
			return (0);
		}
		arg++;
	}
	return (1);
}

int	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;
	char	*arg;

	exit_status = 0;
	if (!cmd->arguments)
	{
		exit_status = EXIT_SUCCESS;
	}
	else
	{
		arg = (char *)cmd->arguments->data;
		if (!is_valid_numeric(arg))
		{
			msh->last_exit_status = 255;
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		}
		exit_status = ft_atoi(arg);
		if (cmd->arguments->next != NULL)
		{
			msh->last_exit_status = EXIT_FAILURE;
			error("exit\ntoo many arguments");
			return (EXIT_FAILURE);
		}
	}
	ft_printf("exit\n");
	msh->last_exit_status = exit_status;
	exit(exit_status);
	return (exit_status);
}
