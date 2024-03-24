/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:48:43 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 11:21:03 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	cmd_is_builtin(char *command)
{
	char	*builtins[9];
	int		i;

	builtins[0] = "env";
	builtins[1] = "pwd";
	builtins[2] = "export";
	builtins[3] = "echo";
	builtins[4] = "exit";
	builtins[5] = "cd";
	builtins[6] = "unset";
	builtins[7] = "test";
	builtins[8] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command, builtins[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}
