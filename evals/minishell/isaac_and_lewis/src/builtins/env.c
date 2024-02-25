/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:46:41 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:08:30 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins.h"

/**
 * @brief  writes environmental variables to the standard output
 *
 * The env utility writes each of our envv strings, separated by newline ('\n')
 * to the standard output. It will only output envv list if there is only 
 * one argument: the command itself. (any more is not required by subject)
 *
 * @param char **args The arguments of our call 
 * @param char ***envp ptr to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	builtin_envv(char **args, char ***envp)
{
	int		i;
	int		j;
	char	**envv;

	i = 0;
	envv = *envp;
	while (args[i])
		i++;
	if (i <= 1)
	{
		j = 0;
		while (envv[j])
		{
			if (ft_strrchr((const char *)envv[j], '='))
			{
				write(1, envv[j], ft_strlen(envv[j]));
				write(1, "\n", 1);
			}
			j++;
		}
	}
	else
		return (1);
	return (0);
}
