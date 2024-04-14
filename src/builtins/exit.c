/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:45 by sentry            #+#    #+#             */
/*   Updated: 2024/04/14 15:06:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	handle_too_many_args() is a helper function used to print an error message
	and return (1) for ft_cd().

	Inputs
	None.

	Outputs
	Returns int(1).
*/

int	handle_too_many_args(void)
{
	ft_printf("cd: too many arguments\n");
	return (1);
}

/*
 	Summary
	is_valid_numeric() checks if a given string is a valid numeric argument.
	
	Inputs
	[const char *] arg: the string to check.
	
	Outputs
	1 if the given string is a valid numeric argument, 0 otherwise (e.g. if 
	given argument is NULL, empty string, or not a 0-9 digit).
*/

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

/*
	Summary
	handles the builtin command 'exit'.

	Inputs
	[t_msh *] msh: A pointer to the main struct of the shell.
	[t_cmd *] cmd: A pointer to the command struct representing the 'exit' 
	command.

	Outputs
	
	ft_exit() sets the last_exit_status member of the msh struct to exit_status 
	and calls the exit function with exit_status (an integer representing 
	the exit status of the shell). If the command has arguments, a numeric 
	check is done and (if not valid), the fn exits the shell with an exit_status 
	of 2. If the numeric check is passed but there are too many arguments, the 
	fn exits the shell with an exit_status of EXIT_FAILURE. Otherwise, the fn 
	exits the shell with an exit_status of 0 and prints "exit\n" to stdout if 
	no arguments.  
*/

int	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int	exit_status;

	exit_status = 0;
	if (cmd->arguments)
	{
		if (is_valid_numeric((char *)cmd->arguments->data))
		{
			exit_status = ft_atoi((char *)cmd->arguments->data);
			if (cmd->arguments->next != NULL)
			{
				msh->last_exit_status = EXIT_FAILURE;
				error("exit\ntoo many arguments");
				return (EXIT_FAILURE);
			}
		}
		else
		{
			msh->last_exit_status = 255;
			msh_error_exit(msh, "exit\nnumeric argument required");
		}
	}
	ft_printf("exit\n");
	msh->last_exit_status = exit_status;
	exit(exit_status);
	return (exit_status);
}

/*
// OG FT_EXIT (working but > 25 lines)
int	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;
	char	*arg;

	exit_status = 0;
	if (!cmd->arguments)
		exit_status = EXIT_SUCCESS;
	else
	{
		arg = (char *)cmd->arguments->data;
		if (!is_valid_numeric(arg))
		{
			msh->last_exit_status = 2;
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
*/
