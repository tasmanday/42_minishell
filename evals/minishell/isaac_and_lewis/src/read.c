/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:47 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 14:08:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/**
 * @brief Intake user commands and arguments to be parsed and executed.
 * If valid, add to our history.
 *
 * @param prompt: The prompt given prior to readline/user input.
 * @param envv: Valid environmental variable array.
 */
char	*msh_readline(char *prompt, char **envv, int *last_exit_ptr)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		if (isatty(STDIN_FILENO))
			write(2, "exit\n", 5);
		free_char_array(envv);
		exit(*last_exit_ptr);
	}
	if (line[0] != '\0')
	{
		add_history(line);
	}
	return (line);
}
