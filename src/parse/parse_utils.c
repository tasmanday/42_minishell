/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:49 by atang             #+#    #+#             */
/*   Updated: 2024/04/14 18:32:21 by tday             ###   ########.fr       */
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

/*
	Summary
	Gets the open flags for file opening based on whether or not append mode
	is requested.

	Inputs
	[bool] is_append: Flag indicating whether append mode is requested.

	Outputs
	[int] Open flags for file opening.

	Note
	Uses bitwise OR operator (|) to combine flags for file creation (O_CREAT),
	write-only mode (O_WRONLY), and append mode (O_APPEND or 0) or
	truncate mode (O_TRUNC or 0), depending on the value of is_append.
*/
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

/*
	Summary
	Processes file descriptors for pipe redirection between consecutive commands
	in the minishell.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	None. Modifies file descriptors for pipe redirection between consecutive
	commands.
*/
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
