/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:52:17 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 20:52:17 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	has_path(char *string)
{
	if (ft_strchr(string, '/') != NULL)
		return (true);
	return (false);
}

static char	**split_path(t_msh *msh)
{
	char	*path_value;
	char	**path_array;
	int		i;
	int		len;
	char	*new_path;

	path_value = get_env_value(msh->envvar, "PATH");
	if (!path_value)
		msh_error_exit(msh, "split_path value error");
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

char	*get_path(t_msh *msh, char *command)
{
	char	**path_array;
	char	*absolute_path;
	int		i;

	path_array = split_path(msh);
	i = 0;
	while (path_array[i])
	{
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
