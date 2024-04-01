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

static char	*get_prompt(t_msh *msh)
{
	char	*prompt;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = ft_strjoin(get_env_value(msh->envvar, "USER"), "@");
	str2 = ft_strjoin(str1, get_env_value(msh->envvar, "NAME"));
	str3 = ft_strjoin(GREEN, str2);
	str4 = ft_strjoin(str3, DEF);
	free(str1);
	free(str2);
	free(str3);
	str1 = ft_strjoin(str4, ":");
	str2 = ft_strjoin(BLUE, get_env_value(msh->envvar, "PWD"));
	str3 = ft_strjoin(str2, DEF);
	free(str4);
	str4 = ft_strjoin(str1, str3);
	prompt = ft_strjoin(str4, "💲 ");
	free(str1);
	free(str2);
	free(str3);
	free(str4);
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
