/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:49 by atang             #+#    #+#             */
/*   Updated: 2024/04/14 17:43:17 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	checks if a given string is a redirection symbol.

	Inputs
	[char *] str: The string to be checked for redirection symbol.

	Outputs
	returns true if the given string is a redirection symbol, and false
	if it's not.
*/
bool	is_redirect(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<") || \
		!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (true);
	else
		return (false);
}

int	get_open_flags(bool is_append)
{
	int	open_flags;

	open_flags = O_CREAT | O_WRONLY;
	if (is_append)
		open_flags |= O_APPEND;
	else
		open_flags |= O_TRUNC;
	return (open_flags);
}

void	process_pipe_fds(t_msh *msh)
{
	int		pipefd[2];
	t_cmd	*cmd_data;
	t_cmd	*next_cmd_data;
	t_dlist	*curr_cmd;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd->next)
	{
		pipe(pipefd);
		cmd_data = curr_cmd->data;
		next_cmd_data = curr_cmd->next->data;
		cmd_data->out_fd = pipefd[1];
		next_cmd_data->in_fd = pipefd[0];
		curr_cmd = curr_cmd->next;
	}
	cmd_data = curr_cmd->data;
}
