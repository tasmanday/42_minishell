/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:37:38 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/25 14:01:29 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

/**
 * @brief  locate a command in the system's PATH.
 *
 *	This function takes in a command (as a string) and an environmental variable 
 *	char **array.
 *	It searches the environment for the PATH variable,
 *	splits its value using ':' as a delimiter to get a list of paths, 
 *	and then checks if the command exists in any of these paths. 
 *
 * @param char *cmd name of the command in question. 
 * @param char **envv a valid environmental variable array.
 * @return full path as heap char string.
 * @return NULL if path is not found.
*/
char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*res;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (!(env[i]))
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		res = ft_strjoin(path, cmd);
		free(path);
		if (access(res, F_OK) == 0)
			return (free_char_array(paths), res);
		else
			free(res);
	}
	free_char_array(paths);
	return (NULL);
}

/**
 * @brief Boolean check if a path is a directory.
 * 
 * Takes an absolute path and checks if it is a directory.
 * 
 * @param path The path to be checked.
 * @return int 1 if it is a directory, 0 if it is not.
 */
int	is_directory(const char *path)
{
	struct stat	stat_buff;

	stat(path, &stat_buff);
	return (S_ISDIR(stat_buff.st_mode));
}

/**
 * @brief Searches for a command string
 * 
 * Checks if the command is in abosolute or relative form. If in absolute form
 * returns the path.
 * 
 * If relative, searches PATH for the command.
 * 
 * Returns the command string if successful. Otherwise NULL if unable to find
 * the command path.
 * 
 * @param str The search string.
 * @param envp The environment (containing PATH to search within)
 * @return char* Char string with the full path if found. NULL if not found.
 */
char	*command_search(char *str, char ***envp)
{
	char	*full_path_str;

	full_path_str = NULL;
	if (ft_isinstr('/', str))
	{
		full_path_str = ft_strdup(str);
		return (full_path_str);
	}
	full_path_str = get_path(str, *envp);
	if (full_path_str)
	{
		return (full_path_str);
	}
	if (full_path_str == NULL)
	{
		return (NULL);
	}
	return (NULL);
}

/**
 * 	@brief  If the command in question is in the PWD, return it.
 *
 *	This function is similar to ft_path, but instead of searching for the 
 *	PATH variable, it searches for the PWD (Present Working Directory) 
 *	variable in the environment.
 *
 *	It then appends the command to the PWD and checks if the command 
 *	exists in this path.
 *
 * 	TODO: Check for leaks
 *
 * @param char *cmd name of the command in question. 
 * @param char **envv a valid environmental variable array.
 * @return 0 on successful execution
 * @return NULl if an error occurs.
*/

char	*get_pathpos(char *cmd, char **env)
{
	int		i;
	int		k;
	char	*pathpos;
	char	*res;
	int		len;

	i = 0;
	k = -1;
	if (!(env))
		exit(1);
	while (env[i] && ft_strnstr(env[i], "PWD=", 4) == 0)
		i++;
	if (!(env[i]))
		exit(0);
	len = (ft_strlen(env[i]) - 4);
	pathpos = (char *)malloc(sizeof(char) * len);
	while (++k < len)
		pathpos[k] = env[i][k + 4];
	pathpos = ft_strjoin(pathpos, "/");
	res = ft_strjoin(pathpos, cmd);
	if (access(res, F_OK) == 0)
		return (res);
	else
		free(res);
	exit(0);
}
