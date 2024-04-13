/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:52:17 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 19:46:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Checks if a string contains a '/' character, indicating it is a path.

	Inputs
	[char *] str: The string to be checked.

	Outputs
	[bool] true if the string contains a '/', otherwise false.
*/
bool	has_path(char *str) // needs to start with '/' or './'
{
	if (ft_strchr(str, '/') != NULL && (str[0] == '/' || str[0] == '.'))
		return (true);
	return (false);
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the path array.
 
	Summary
	splits the PATH environment variable into an array of directory paths.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	[char **] path_array: an array of directory paths extracted from the
 		PATH environment variable.
*/
static char	**split_path(t_msh *msh)
{
	char	*path_value;
	char	**path_array;
	int		i;
	int		len;
	char	*new_path;

	path_value = get_env_value(msh->envvar, "PATH");
	if (!path_value)
		msh_error_exit(msh, "No such file or directory");
	path_array = ft_split(path_value, ':');
	if (!path_array)
		msh_error_exit(msh, "split_path array error");
	i = 0;
	while (path_array[i])
	{
		len = ft_strlen(path_array[i]);
		if (path_array[i][len - 1] != '/')
		{
			new_path = ft_strjoin(path_array[i], "/");
			free(path_array[i]);
			path_array[i] = new_path;
		}
		i++;
	}
	return (path_array);
}

/*
	**** ALLOCATES MEMORY ****
 	memory is allocated for the returned path string.
  
	Summary
	Searches for the absolute path of a command in the directories listed in
 	the PATH environment variable.

	Inputs
	[t_msh *] msh: the main minishell structure.
	[char *] command: the command for which the absolute path needs to be found.

	Outputs
	[char *] absolute_path: the absolute path of the command if found and
 		executable, otherwise NULL.
*/
char	*get_path(t_msh *msh, char *command)
{
	char	**path_array;
	char	*absolute_path;
	int		i;

//	debug("NO PATH/ get_path");
	path_array = split_path(msh);
	i = 0;
	while (path_array[i])
	{
//		ft_printf("checking path: %s\n", path_array[i]);
		absolute_path = ft_strjoin(path_array[i], command);
		if (!absolute_path)
			msh_error_exit(msh, "get_path strjoin error");
		if (access(absolute_path, X_OK) == 0)
		{
			free_array((void **)path_array);
			return (absolute_path);
		}
		free (absolute_path);
		i++;
	}
	free_array((void **)path_array);
	return (NULL);
}
