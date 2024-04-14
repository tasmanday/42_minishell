/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:50:08 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:38:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Handles cases where an environment variable doesn't exist in the list of 
	environmental variables.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.
	[int *] i: Pointer to the index in the input string.
	[char *] key: The key of the environment variable.

	Outputs
	None. Modifies the input string by removing the environment variable.
*/
void	handle_no_value(t_msh *msh, int *i, char *key)
{
	int		length;
	char	*temp_str;

	if (ft_strcmp(key, "?") == 0)
	{
		*i += 2;
		free(key);
		return ;
	}
	length = ft_strlen(key);
	temp_str = ft_replace_substr(msh->input, *i, (*i + length + 1), "");
	free(msh->input);
	msh->input = temp_str;
	free(key);
}

/*
	Summary
	expands environment variables in the given string by replacing them with
	their corresponding values.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.
	[int *] i: Pointer to the index in the input string.

	Outputs
	None. Modifies the input string by expanding environment variables.
*/
void	expand_envvar(t_msh *msh, int *i)
{
	int		length;
	char	*key;
	char	*value;
	char	*temp_str;

	key = get_env_key(msh->input + *i + 1);
	value = get_env_value(msh->envvar, key);
	if (!value)
		handle_no_value(msh, i, key);
	else
	{
		length = ft_strlen(key);
		temp_str = ft_replace_substr(msh->input, *i, (*i + length + 1), value);
		free(msh->input);
		msh->input = temp_str;
		free(key);
		*i = *i + ft_strlen(value);
	}
}
