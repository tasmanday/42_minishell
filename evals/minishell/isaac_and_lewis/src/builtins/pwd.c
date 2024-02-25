/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:26:26 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/05 18:28:34 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins.h"

/**
 * @brief  prints the absolute pathname of the current working directory.
 *
 * @param char **args The arguments of our call 
 * @param char ***envp ptr to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	builtin_pwd(char **args, char ***envp)
{
	int		i;
	char	**spl;
	char	**envv;

	i = 0;
	spl = NULL;
	envv = *envp;
	while (envv[i])
	{
		if (ft_strncmp(envv[i], "PWD", ft_strlen(args[0])) == 0)
		{
			spl = ft_split(envv[i], '=');
			printf("%s\n", spl[1]);
			free_char_array(spl);
			return (0);
		}
		i++;
	}
	return (1);
}
