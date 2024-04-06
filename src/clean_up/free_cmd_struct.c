/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:02:08 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 21:03:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees the memory allocated for a t_cmd structure and its associated data.
	this function can be passed to dlist_del_all() to free allocated memory at
	each node of a doubly linked list before deleting them.

	Inputs
	[void *] data: a pointer to a t_cmd structure that needs to be freed,
		cast as a void pointer so that it can be used by the dlst_del_all()
		function.
	
	Outputs
	none. the function frees the memory allocated for the t_cmd structure and
	its associated data.
*/
void	free_cmd_struct(void *data)
{
	t_cmd	*cmd;
	t_list	*curr_arg;
	t_list	*next_arg;

	cmd = (t_cmd *)data;
	if (!cmd)
		return ;
	curr_arg = cmd->arguments;
	while (curr_arg)
	{
		next_arg = curr_arg->next;
		if (curr_arg->data)
			free(curr_arg->data);
		free(curr_arg);
		curr_arg = next_arg;
	}
	if (cmd->command)
		free(cmd->command);
	if (cmd->input_file)
		free(cmd->input_file);
	if (cmd->output_file)
		free(cmd->output_file);
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
	if (cmd->heredoc_delimiter)
		free(cmd->heredoc_delimiter);
	if (cmd->heredoc_data)
		free(cmd->heredoc_data);
	free(cmd);
}
