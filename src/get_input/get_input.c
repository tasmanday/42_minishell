/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:13:05 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* static char	*get_prompt(t_msh *msh)
{
	char	*prompt;

	prompt = ft_strjoin_any(13, GREEN, get_env_value(msh->envvar, "USER"), DEF,\
		":", CYAN, get_env_value(msh->envvar, "SHLVL"), DEF, ":", BLUE, \
		get_env_value(msh->envvar, "PWD"), CYAN, "$ ", DEF);
	return (prompt);
} */

static char	*get_prompt(t_msh *msh)
{
	char	*prompt;

	prompt = ft_strjoin_any(9, GREEN, get_env_value(msh->envvar, "SHLVL"), DEF, \
		":", BLUE, get_env_value(msh->envvar, "PWD"), CYAN, "$ ", DEF);
	return (prompt);
}

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
char	*get_input(t_msh *msh)
{
	char	*line;
	char	*prompt;

	prompt = get_prompt(msh);
	line = readline(prompt);
	if (!line)
	{
		ft_printf("exit\n");
		free_everything(msh);
		exit(EXIT_SUCCESS);
	}
	if (line[0] != '\0')
	{
		add_history(line);
	}
	free(prompt);
	return (line);
}
