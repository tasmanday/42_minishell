/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:01:44 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 22:37:02 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_and_null(char **str)
{
	free(*str);
	*str = NULL;
}

char	**builtin_unset_init(int *i, int *j, char **envv)
{
	int		len;
	char	**n_envv;

	*i = 0;
	*j = 0;
	len = 0;
	while (envv[len])
		len++;
	n_envv = malloc(sizeof(char *) * (len + 1));
	return (n_envv);
}

/**
 * @brief  	removes given environmental variable from our environmental
 * 			variables.
 *
 * @param 	char *u_str The env variable we would like to unset. 
 * @param 	char **envv ptr to a valid environmental variable array.
 * @return 	char ** new envv on successful execution
 * @return 	NULL if an error occurs.
*/
char	**builtin_unset_arg(char *u_str, char **envv)
{
	int		i;
	int		j;
	char	**n_envv;
	char	*temp;

	n_envv = builtin_unset_init(&i, &j, envv);
	if (!n_envv)
		return (NULL);
	while (envv[i])
	{
		temp = envv_to_key(envv, envv[i], 0);
		if (!(ft_strncmp(temp, u_str, ft_strlen(temp)) == 0))
		{
			free_and_null(&temp);
			n_envv[j] = ft_strdup(envv[i]);
			if (!n_envv[j])
				return (free_char_array(envv), free_array_til(n_envv, j), NULL);
			j++;
		}
		else
			free_and_null(&temp);
		i++;
	}
	n_envv[j] = NULL;
	return (free_char_array(envv), n_envv);
}

/**
 * @brief  unsets an environmental variable found within args[1].
 *
 * @param char **args The arguments of our call 
 * @param char ***envp ptr to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	builtin_unset(char **args, char ***envp)
{
	char	**envv;
	char	*temp;

	envv = *envp;
	if (args[1] == NULL)
	{
		print_err("unset: provide a valid variable name\n");
		return (1);
	}
	temp = msh_getenv(*envp, args[1]);
	if (temp == NULL)
	{
		print_err("unset: %s: no such env variable!\n", args[1]);
		return (1);
	}
	else
	{
		free(temp);
		*envp = (builtin_unset_arg(args[1], envv));
		if (!*envp)
			return (1);
		return (0);
	}
	return (1);
}
