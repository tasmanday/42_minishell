/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:53:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* 
better prompt

static char	*get_prompt(t_msh *msh)
{
	char	*prompt;

	prompt = ft_strjoin_any(13, GREEN, get_env_value(msh->envvar, "USER"), DEF,\
		":", CYAN, get_env_value(msh->envvar, "SHLVL"), DEF, ":", BLUE, \
		get_env_value(msh->envvar, "PWD"), CYAN, "$ ", DEF);
	return (prompt);
}
*/

/*
	**** ALLOCATES MEMORY ****
	memory allocated for the returned string needs to be freed after use.

	Summary
	Constructs the prompt string for the minishell.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	[char *] Pointer to the constructed prompt string.
*/
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

/*
	Summary
	Checks if a string contains only whitespace characters.

	Inputs
	[char *] input: Pointer to the input string to be checked.

	Outputs
	[bool] Returns true if the string contains only whitespace characters,
	otherwise returns false.
*/
bool	is_just_whitespace(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
			return (false);
		i++;
	}
	return (true);
}
