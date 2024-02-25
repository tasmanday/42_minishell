/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:51:46 by wmakaran          #+#    #+#             */
/*   Updated: 2023/08/14 18:52:29 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

char	**ft_env_paths(char *envp[])
{
	char	**ptr;
	char	**paths;
	char	*tmp;

	if (!envp)
		return (NULL);
	ptr = envp;
	while (*ptr)
	{
		if (ft_strncmp("PATH=", *ptr, 5) == 0)
		{
			tmp = ft_substr(*ptr, 5, ft_strlen(*ptr) - 5);
			paths = ft_split(tmp, ':');
			free(tmp);
			return (paths);
		}
		ptr++;
	}
	return (NULL);
}

char	*ft_cmd_path(char *cmd, char **paths)
{
	char	**paths_ptr;
	char	*cmd_path;
	char	*tmp;

	if (!paths)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	paths_ptr = paths;
	while (*paths_ptr)
	{
		tmp = ft_strjoin(*paths_ptr, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths_ptr++;
	}
	return (NULL);
}

// Test
/*
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	char	**paths;
    char	**ptr;

	paths = ft_env_paths(envp);
	ptr = paths;
	while (*ptr)
	{
		printf("%s\n", *ptr);
		ptr++;
	}
	printf("%s\n",ft_cmd_path("grep", paths));
	return (0);
}
*/
