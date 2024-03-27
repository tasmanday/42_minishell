void	process_pipe_fds(t_msh *msh)
{
	int		pipefd[2];
	t_cmd	*cmd_data;
	t_cmd	*next_cmd_data;
	t_dlst	*curr_cmd;

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
}

void	process_redir_fds(t_msh *msh)
{
	int		fd;
	t_cmd	*cmd_data;
	t_cmd	*next_cmd_data;
	t_dlst	*curr_cmd;

	curr_cmd = msh->cmd_queue;
	while (curr_cmd)
	{
		cmd_data = curr_cmd->data;
		if (cmd_data->input_file)
			cmd_data->in_fd = open(cmd_data->input_file, O_RDONLY);
		if (cmd_data->output_file)
		{
			if (cmd_data->out_fd != STDOUT_FILENO)
			{
				close(cmd_data->out_fd);
				cmd_data->out_fd = open(cmd_data->output_file, O_CREAT | O_WRONLY, 0777);
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
		curr_cmd = curr_cmd->next;
	}
}

void	process_fds(t_msh *msh)
{
	if (msh->num_of_cmds > 1)
		process_pipe_fds(msh);
	process_redir_fds(msh);
	// update to redirect fd, (overwrites pipe fd)
			
    
