void	process_fds(t_msh *msh)
{
	int		pipefd[2];
	t_cmd	*cmd_data;
	t_cmd	*next_cmd_data;
	t_dlst	*curr_cmd;

	curr_cmd = msh->cmd_queue;
	if (msh->num_of_cmds > 1)
	{
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
	// update to redirect fd, (overwrites pipe fd)
			
    
