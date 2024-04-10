/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:50:08 by tday              #+#    #+#             */
/*   Updated: 2024/04/07 19:48:12 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	expands environment variables in the given string by replacing them with
	their corresponding values.

	Inputs
	[t_dlist *] envvar: a doubly linked list containing environment variables.
	[char **] str: a string pointer representing the string to be expanded.
	[int *] i: an integer pointer representing the index to track the position
		in the string.
	
	Outputs
	none. the function expands the environment variable in place within the
	string.
*/
/* void	expand_envvar(t_dlist *envvar, char **str, int *i)
{
	int		length;
	char	*key;
	char	*value;

	key = get_env_key(*str + *i + 1);
	value = get_env_value(envvar, key);
	if (!value)
	{
		length = ft_strlen(key);
		ft_replace_substr(str, *i, (*i + length + 1), "");
		free(key);
	}
	else
	{
		length = ft_strlen(key);
		ft_replace_substr(str, *i, (*i + length + 1), value);
		free(key);
		*i = *i + ft_strlen(value);
	}
} */

void	expand_envvar(t_msh *msh, int *i)
{
	int		length;
	char	*key;
	char	*value;
	char	*temp_str;

	key = get_env_key(msh->input + *i + 1);
	value = get_env_value(msh->envvar, key);
	if (!value)
	{
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

