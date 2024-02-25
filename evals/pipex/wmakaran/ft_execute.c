/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:03:19 by wmakaran          #+#    #+#             */
/*   Updated: 2023/08/14 20:31:51 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	ft_execute(char *full_cmd, char **paths, int fd_in, int fd_out)
{
	char	**cmd_params;
	char	*cmd_path;
	int		exec_return;
	int		pid;
	int		res;

	pid = fork();
	if (pid == 0)
	{
		cmd_params = ft_split(full_cmd, ' ');
		cmd_path = ft_cmd_path(cmd_params[0], paths);
		if (!cmd_path)
			ft_custom_error(cmd_params[0], "command not found");
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		exec_return = execve(cmd_path, cmd_params, NULL);
		ft_free_strs(cmd_params);
		free(cmd_path);
		exit(exec_return);
	}
	else
		wait(&res);
	if (res != 0)
		exit(-1);
	return (res);
}

// Test
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	int		res;
	int		input_fd;
	int		output_fd;
	int		pipe_fd[2];
	int		tmp;
	char	**paths;

	paths = ft_env_paths(envp);
	pipe(pipe_fd);
	input_fd = open("infile", O_RDONLY);
	output_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	printf("input_fd: %d  output_fd: %d  pipe_fd_0: %d  pipe_fd_1: %d\n",
		input_fd, output_fd, pipe_fd[0], pipe_fd[1]);
	res = ft_execute("cat", paths, input_fd, pipe_fd[1]);
	printf("cat res: %d\n", res);
	close(pipe_fd[1]);
	res = ft_execute("grep -v test", paths, pipe_fd[0], output_fd);
	printf("grep res: %d\n", res);
	close(input_fd);
	close(output_fd);
	printf("program end\n");
	return (0);
}
*/
