/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 21:58:33 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* 
	**** ALLOCATES MEMORY ****
	memory allocated for the returned string needs to be freed after use.

	Summary
	using readline, prompts the user and then reads a line of input. if the
	line is not empty it adds it to the working history, and handles errors if
	readline fails.

	Inputs
	[t_msh *] msh: a pointer to the shell's main structure, used for freeing
		resources on error.
	[char *] prompt: a pointer to a string that contains the prompt to be
		displayed to the user.

	Outputs
	[char *] line: a dynamically allocated string containing the user's input.
*/
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
