/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/03/04 20:50:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_input(t_msh *msh, char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		if (isatty(STDIN_FILENO))
			error("readline error");
		free_everything(msh);
		exit(EXIT_FAILURE); // update to last exit status
	}
	if (line[0] != '\0')
	{
		add_history(line);
	}
	return (line);
}
