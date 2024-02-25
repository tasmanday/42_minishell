/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:15:34 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 19:13:37 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	enter_heredoc(char *delimiter, char **envv, int last_exit, int *heredoc_fd)
{
	int		error_return;
	int		buff_fd[2];
	pid_t	pid;
	int		ret;

	error_return = preprocess_redirection_word(&delimiter, envv, last_exit);
	if (error_return)
		return (free(delimiter), 1);
	error_return = pipe(buff_fd);
	if (error_return < 0)
		return (free(delimiter), 1);
	pid = fork();
	if (pid == 0)
		gui_tobuff(delimiter, envv, last_exit, buff_fd[1]);
	waitpid(pid, &ret, 0);
	free(delimiter);
	close(buff_fd[1]);
	if (WIFSIGNALED(ret))
	{
		*heredoc_fd = buff_fd[0];
		return (128 + WTERMSIG(ret));
	}
	*heredoc_fd = buff_fd[0];
	return (0);
}

int	enter_heredocs(t_deque d, char **envv, int last_exit)
{
	t_dlist			*node;
	t_token_node	*token;
	int				ret;
	int				fd;

	if (!d.head)
	{
		return (0);
	}
	node = d.head;
	while (node)
	{
		token = node->content;
		if (token && token->type == REDIRECTION_DELIMITER)
		{
			token->type = REDIRECTION_HEREDOC;
			ret = enter_heredoc(token->content.str, envv, last_exit, &fd);
			token->content.fd = fd;
			if (ret)
				return (ret);
		}
		node = node->next;
	}
	return (0);
}
