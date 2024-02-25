/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:21:46 by wmakaran          #+#    #+#             */
/*   Updated: 2023/08/15 17:34:19 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_file_fd_init(int file_fd[], char *infile, char *outfile)
{
	file_fd[0] = open(infile, O_RDONLY);
	if (file_fd[0] < 0)
		ft_error(infile);
	file_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd[1] < 0)
		ft_error(outfile);
}

// Open 1st and last file. Then run commands.
static void	ft_pipex(int argc, char *argv[], char **paths)
{
	int		file_fd[2];
	int		pipe_fd[2];
	int		prev_pipe_fd_0;
	int		i;

	prev_pipe_fd_0 = -1;
	ft_file_fd_init(file_fd, argv[1], argv[argc - 1]);
	i = 1;
	while (++i < argc - 1)
	{
		if (pipe(pipe_fd) < 0)
			ft_error("pipe's file descriptor");
		if (i == 2)
			ft_execute(argv[i], paths, file_fd[0], pipe_fd[1]);
		else if (i == argc - 2)
			ft_execute(argv[i], paths, prev_pipe_fd_0, file_fd[1]);
		else
			ft_execute(argv[i], paths, prev_pipe_fd_0, pipe_fd[1]);
		close(pipe_fd[1]);
		close(prev_pipe_fd_0);
		prev_pipe_fd_0 = dup(pipe_fd[0]);
	}
	close(file_fd[0]);
	close(file_fd[1]);
	close(prev_pipe_fd_0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5)
		ft_custom_error("args", "4 or more arguments only.");
	else
	{
		paths = ft_env_paths(envp);
		ft_pipex(argc, argv, paths);
		ft_free_strs(paths);
	}
	exit(0);
	return (0);
}
