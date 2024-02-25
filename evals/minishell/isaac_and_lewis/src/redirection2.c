/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:24:41 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 12:50:37 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

/**
 * @brief Opens file descriptors in appropriate mode for this redirection
 * 
 * Heredocs are passed. They would have the fd already created when the heredoc
 * was made (and stored in the buffer) so they do not need to have a file opened
 * for it to be used.
 * 
 * @param r The redirection to have a FD opened.
 * @return 1 if error. 0 if success
 */

void	open_fd_err_fds(t_redirection *r)
{
	r->old_fd = -1;
	r->new_fd = -1;
}

int	open_fd(t_redirection *r)
{
	int	fd;

	if (r->type == REDIRECTION_NONE)
		return (open_fd_err_fds(r), 1);
	if (r->type == REDIRECTION_OUT || r->type == REDIRECTION_OUT_APPEND)
	{
		if (r->type == REDIRECTION_OUT)
			fd = open(r->file_name, O_CREAT | O_WRONLY | O_CLOEXEC, 0644);
		else
			fd = open(r->file_name, O_CREAT | O_WRONLY | O_APPEND
					| O_CLOEXEC, 0644);
		if (fd < 0)
			return (print_open_error(r->file_name), 1);
		r->old_fd = 1;
		r->new_fd = fd;
	}
	if (r->type == REDIRECTION_IN)
	{
		fd = open(r->file_name, O_RDONLY | O_CLOEXEC);
		if (fd < 0)
			return (print_open_error(r->file_name), 1);
		r->old_fd = 0;
		r->new_fd = fd;
	}
	return (0);
}

/**
 * @brief Open file descriptors for all redirections in this list.
 * 
 * @param redirections The list of redirections.
 * @return bubbled error (1) if error. 0 if success
 */
int	open_fds(t_list	*redirections)
{
	t_redirection	*r;
	int				err_return;

	while (redirections)
	{
		r = redirections->content;
		if (!r)
		{
			break ;
		}
		err_return = open_fd(r);
		if (err_return != 0)
		{
			return (err_return);
		}
		redirections = redirections->next;
	}
	return (0);
}
