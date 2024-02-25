/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:58:37 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:01:53 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins.h"

/**
 * @brief determine whether or not a given string is a relative path string. 
 *
 * @param char *str our comparison string.
 * @return 1 if it is a relative path.
 * @return -1 if there is leading white space?
 * @return 0 if it is not a relative path.
*/
int	is_relative_path(char *str)
{
	if (str[0] == '/')
	{
		return (0);
	}
	else if (ft_isalpha(str[0]))
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

/**
 * @brief  caller for our builtin export function. sets dest=src.
 *
 * @param char **args The arguments of our call 
 * @param char ***envp pointer to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	update_envv(char *dest, char *src, char ***envp)
{
	char	*str1;
	char	*str2;
	char	*export_call[3];

	str1 = ft_strjoin(dest, "=");
	if (!str1)
	{
		return (1);
	}
	str2 = ft_strjoin(str1, src);
	free(str1);
	if (!str2)
	{
		free(str1);
		return (1);
	}
	export_call[0] = "export";
	export_call[1] = str2;
	export_call[2] = NULL;
	builtin_export(export_call, envp);
	free(str2);
	return (0);
}

/**
 * @brief  caller to update our env array with new PWD, OLDPWD.
 *
 * @param temp_pwd The pwd of our old working directory.
 * @param char ***envp pointer to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	update_both_envvs(char *temp_pwd, char ***envp)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		print_err("msh_internal: update_both_envs: getcwd error\n");
		return (1);
	}
	else
	{
		update_envv("PWD", cwd, envp);
	}
	update_envv("OLDPWD", temp_pwd, envp);
	return (0);
}

/*
 * NORM HELPER
*/
int	cd1(char *home_path, char *temp_pwd, char ***envp)
{
	home_path = msh_getenv(*envp, "HOME");
	chdir(home_path);
	update_both_envvs(temp_pwd, envp);
	free(temp_pwd);
	free(home_path);
	return (0);
}

/**
 * @brief  change current working directory.
 *
 * @param char **args The arguments of our call 
 * @param char ***envp pointer to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	builtin_cd(char **args, char ***envp)
{
	char		*temp_pwd;
	char		*home_path;
	struct stat	path_stat;

	if (args[1] && ft_strlen(args[1]) == 0)
		return (0);
	home_path = NULL;
	temp_pwd = msh_getenv(*envp, "PWD");
	if (!args[1])
		return (cd1(home_path, temp_pwd, envp));
	if (ft_strlen(args[1]) > 255)
		return (cd2(args, temp_pwd));
	stat(args[1], &path_stat);
	if (S_ISREG(path_stat.st_mode) && access(args[1], F_OK) != -1)
		return (cd3(args, temp_pwd));
	else if (S_ISDIR(path_stat.st_mode))
	{
		if (chdir(args[1]) == 0)
			return (cd4(temp_pwd, envp));
		else
			return (cd5(temp_pwd, args));
	}
	else
		return (cd6(temp_pwd, args));
	return (0);
}
