/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:57:08 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 17:03:31 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

/*
 * NORM_HELPERS 
*/
int	fab(char *str)
{
	free(str);
	return (1);
}

int	guib_init(int *was_quoted, char *delimiter)
{
	*was_quoted = str_has_quote_char(delimiter);
	remove_quotes_string(delimiter);
	sig_initialiser_during_heredoc_child();
	return (0);
}

void	guib_do(char *line, char **envv, int last_exit, int write_buff)
{
	char	*expanded_line;

	expanded_line = make_expanded_string(line, envv, last_exit);
	write(write_buff, expanded_line, ft_strlen(expanded_line));
	free(expanded_line);
}

int	gui_tobuff(char *delimiter, char **envv, int last_exit, int write_buff)
{
	int		was_quoted;
	char	*line;
	int		line_count;

	line_count = guib_init(&was_quoted, delimiter);
	while (1)
	{
		line = readline(PS2);
		if (!line && fab(line))
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
			break ;
		if (was_quoted)
			write(write_buff, line, ft_strlen(line));
		else
			guib_do(line, envv, last_exit, write_buff);
		write(write_buff, "\n", 1);
		line_count++;
		free(line);
	}
	exit(0);
}
