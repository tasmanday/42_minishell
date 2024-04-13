/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:15:47 by tday              #+#    #+#             */
/*   Updated: 2024/04/06 12:15:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for return which is freed by free_cmd_struct function.
*/
char	*read_heredoc(char *delimiter)
{
	char	*result;
	char	*line;

	result = NULL;
	while (1)
	{
		line = readline("\033[1;37m> \033[0m");
		if (line == NULL)
		break;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break;
		}
		if (result == NULL)
			result = ft_strdup(line);
		else
		{
			result = ft_strjoin(result, "\n");
			result = ft_strjoin(result, line);
		}
		free(line);
	}
	result = ft_strjoin(result, "\n");
	return (result);
}

bool file_exists(const char *file_name)
{
	struct stat	buffer;
	return (stat(file_name, &buffer) == 0);
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the input and output files

	Summary
	handles the redirection of input and output files in a command structure.
	
	Inputs
	[t_cmd *] cmd: a pointer to the command structure (t_cmd) that will
		contain input and output file information.
	[t_tlist **] token_ptr: a pointer to the current token in the token list.

	Outputs
	none. modifies the cmd struct input and output elements based on the
	redirection token.
*/
void	handle_redirection(t_cmd *cmd, t_list **token_ptr)
{
	if ((*token_ptr)->next)
	{
		if (ft_strcmp((char *)(*token_ptr)->data, "<") == 0)
		{
			if (cmd->heredoc_delimiter)
				free_null((void **)&(cmd->heredoc_delimiter));
			*token_ptr = (*token_ptr)->next;
			cmd->input_file = ft_strdup((char *)(*token_ptr)->data);
			if (!file_exists(cmd->input_file))
				ft_printf_fd(cmd->out_fd, "%s%s: No such file or directory%s\n"\
					, RED, cmd->input_file, DEF);
		}
		else if (ft_strcmp((char *)(*token_ptr)->data, "<<") == 0)
		{
			if (cmd->input_file)
				free_null((void **)&(cmd->input_file));
			*token_ptr = (*token_ptr)->next;
			cmd->heredoc_delimiter = ft_strdup((char *)(*token_ptr)->data);
			cmd->heredoc_data = read_heredoc(cmd->heredoc_delimiter);
		}
		else if (ft_strcmp((char *)(*token_ptr)->data, ">") == 0 || \
			ft_strcmp((char *)(*token_ptr)->data, ">>") == 0)
		{
			if (cmd->output_file)
				free_null((void **)&(cmd->output_file));
			if (ft_strcmp((char *)(*token_ptr)->data, ">>") == 0)
				cmd->is_append = true;
			*token_ptr = (*token_ptr)->next;
			cmd->output_file = ft_strdup((char *)(*token_ptr)->data);
		}
	}
}