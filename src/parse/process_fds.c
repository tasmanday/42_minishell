/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:08:26 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 17:42:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	handle_input_file(t_cmd *cmd_data)
{
	int		in_fd;

	if (!file_exists(cmd_data->input_file))
		return ;
	in_fd = open(cmd_data->input_file, O_RDONLY);
	if (cmd_data->in_fd == -1)
	{
		error("process_redir_fds error opening input file");
		return ;
	}
	else
	{
		if (cmd_data->in_fd != STDIN_FILENO)
			close(cmd_data->in_fd);
		cmd_data->in_fd = in_fd;
	}
}

static void	handle_output_file(t_cmd *cmd_data, t_dlist *curr_cmd)
{
	int		out_fd;
	t_cmd	*next_cmd_data;
	int		open_flags;

	open_flags = get_open_flags(cmd_data->is_append);
	out_fd = open(cmd_data->output_file, open_flags, 0644);
	if (out_fd == -1)
		perror("process_redir_fds error opening output file");
	else
	{
		if (cmd_data->out_fd != STDOUT_FILENO)
			close(cmd_data->out_fd);
		cmd_data->out_fd = out_fd;
		if (curr_cmd->next)
		{
			next_cmd_data = curr_cmd->next->data;
			if (next_cmd_data->in_fd != STDIN_FILENO)
			{
				close(next_cmd_data->in_fd);
				next_cmd_data->in_fd = STDIN_FILENO;
			}
		}
	}
}

static void	handle_heredoc(t_cmd *cmd_data)
{
	int	fds[2];

	if (pipe(fds) == -1)
	{
		error("handle_heredoc pipe error");
		return ;
	}
	write(fds[1], cmd_data->heredoc_data, ft_strlen(cmd_data->heredoc_data));
	close(fds[1]);
	if (cmd_data->in_fd != STDIN_FILENO)
		close(cmd_data->in_fd);
	cmd_data->in_fd = fds[0];
}

static void	process_redir_fds(t_msh *msh)
{
	t_cmd	*cmd_data;
	t_dlist	*curr_cmd;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = curr_cmd->data;
		if (cmd_data->heredoc_delimiter)
		{
			handle_heredoc(cmd_data);
		}
		if (cmd_data->input_file)
			handle_input_file(cmd_data);
		if (cmd_data->output_file)
			handle_output_file(cmd_data, curr_cmd);
		curr_cmd = curr_cmd->next;
	}
}

void	process_fds(t_msh *msh)
{
	if (msh->num_of_cmds > 1)
		process_pipe_fds(msh);
	process_redir_fds(msh);
}
