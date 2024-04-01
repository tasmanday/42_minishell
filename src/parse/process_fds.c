/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:08:26 by tday              #+#    #+#             */
/*   Updated: 2024/03/28 21:08:26 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* remove later */
void	print_fds(t_cmd *cmd_data)
{
	ft_printf("in_fd: %i, out_fd: %i\n", cmd_data->in_fd, cmd_data->out_fd);
}

static void	process_pipe_fds(t_msh *msh)
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
		print_fds(cmd_data); // remove later
		curr_cmd = curr_cmd->next;
	}
	cmd_data = curr_cmd->data;
	print_fds(cmd_data); // remopve later
}

static void	handle_input_file(t_cmd *cmd_data)
{
	int		in_fd;

	in_fd = open(cmd_data->input_file, O_RDONLY);
	if (cmd_data->in_fd == -1)
		perror("process_redir_fds error opening input file");
	else
	{
	if (cmd_data->in_fd != STDIN_FILENO)
		close(cmd_data->in_fd);
	cmd_data->in_fd = in_fd;
	debug("redir"); // remove
	print_fds(cmd_data); // remove
	}
}

static void	handle_output_file(t_cmd *cmd_data, t_dlist *curr_cmd)
{
	int		out_fd;
	t_cmd	*next_cmd_data;

	out_fd = open(cmd_data->output_file, O_CREAT | O_WRONLY, 0644);
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
		debug("redir"); // remove
		print_fds(cmd_data); // remove
	}
}

static void	process_redir_fds(t_msh *msh)
{
	t_cmd	*cmd_data;
	t_dlist	*curr_cmd;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = curr_cmd->data;

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
