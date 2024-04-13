/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 19:46:37 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* static char	*get_prompt(t_msh *msh)
{
	char	*prompt;
	char	*str1;
	char	*str2;

	str1 = ft_strjoin(GREEN, get_env_value(msh->envvar, "USER"));
	str2 = ft_strjoin(str1, DEF);
	free(str1);
	str1 = ft_strjoin(str2, ":");
	free(str2);
	str2 = ft_strjoin(str1, BLUE);
	free(str1);
	str1 = ft_strjoin(str2, get_env_value(msh->envvar, "PWD"));
	free(str2);
	str2 = ft_strjoin(str1, CYAN);
	free(str1);
	str1 = ft_strjoin(str2, "$ ");
	prompt = ft_strjoin(str1, DEF);
	free(str1);
	free(str2);
	return (prompt);
} */

static char	*get_prompt(t_msh *msh)
{
	char	*prompt;

	prompt = ft_strjoin_any(13, GREEN, get_env_value(msh->envvar, "USER"), DEF,\
		":", CYAN, get_env_value(msh->envvar, "SHLVL"), DEF, ":", BLUE, \
		get_env_value(msh->envvar, "PWD"), CYAN, "$ ", DEF);
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
//	char	*input;

	prompt = get_prompt(msh);
	line = readline("prompt");
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
//	input = ft_strdup(line);
//	free(line);
//	return (input);
	return (line);
}
