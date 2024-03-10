/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:02:08 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 21:02:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	free(cmd);
}
