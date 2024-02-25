/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:29:28 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 19:24:04 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief	determine whether a given string is a builtin cmd 
 *
 * @param 	char *cmd the query string.
 * @return 	1 if the string is a builtin cmd
 * @return 	0 if not.
*/
int	is_builtin(char *cmd)
{
	char	*name[8];
	int		i;

	if (!cmd)
	{
		return (0);
	}
	name[0] = "cd";
	name[1] = "echo";
	name[2] = "env";
	name[3] = "exit";
	name[4] = "export";
	name[5] = "pwd";
	name[6] = "unset";
	name[7] = NULL;
	i = 0;
	while (name[i])
	{
		if (ft_strncmp(cmd, name[i], ft_strlen(cmd) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief	if our input string is a builtin cmd, return its name. 
 *
 * @param 	char *cmd the query string.
 * @return 	name of builtin cmd on successful execution
 * @return 	NULL otherwise.
 *
*/
char	*builtin_command_search(char *cmd)
{
	char	*name[8];
	int		i;

	if (!cmd)
	{
		return (NULL);
	}
	name[0] = "cd";
	name[1] = "echo";
	name[2] = "env";
	name[3] = "exit";
	name[4] = "export";
	name[5] = "pwd";
	name[6] = "unset";
	name[7] = NULL;
	i = 0;
	while (name[i])
	{
		if (ft_strncmp(cmd, name[i], ft_strlen(cmd) + 1) == 0)
			return (ft_strdup(cmd));
		i++;
	}
	return (NULL);
}

/**
 * @brief	calls our builtin command functions. Returns appropriate err number.
 *
 * @param 	char *cmd the contents of our new environmental variable.
 * @param 	char **args our command arguments, where args[0] is the cmd name.
 * @param 	char ***envp ptr to a valid environmental variable array.
 * @return 	0 on successful execution
 * @return 	>0 if an error occurs.
 * @return	-1 in the case of unexpected behaviour. (something needs fixing)
*/
int	builtin_execve(char *cmd, char **args, char ***envp)
{
	char	*name[7];
	int		(*f_ptr[7])(char **, char ***);
	int		i;

	name[0] = "cd";
	name[1] = "echo";
	name[2] = "env";
	name[3] = "exit";
	name[4] = "export";
	name[5] = "pwd";
	name[6] = "unset";
	f_ptr[0] = &builtin_cd;
	f_ptr[1] = &builtin_echo;
	f_ptr[2] = &builtin_envv;
	f_ptr[3] = &builtin_exit;
	f_ptr[4] = &builtin_export;
	f_ptr[5] = &builtin_pwd;
	f_ptr[6] = &builtin_unset;
	i = -1;
	while (++i < 7)
		if (ft_strncmp(cmd, name[i], ft_strlen(name[i])) == 0)
			return (f_ptr[i](args, envp));
	return (-1);
}
