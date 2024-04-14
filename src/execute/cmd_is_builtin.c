/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:48:43 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:08:43 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
/*
	Summary
	checks if the command is one of our builtin functions.

	Inputs
	[char *] command: the command to be checked.

	Outputs
	[bool]: true if the command is a builtin, false if it's not.
*/
bool	cmd_is_builtin(char *command)
{
	char	*builtins[8];
	int		i;

	builtins[0] = "env";
	builtins[1] = "pwd";
	builtins[2] = "export";
	builtins[3] = "echo";
	builtins[4] = "exit";
	builtins[5] = "cd";
	builtins[6] = "unset";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command, builtins[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}
