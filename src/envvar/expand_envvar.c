/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:50:08 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 22:23:53 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	expands environment variables in the given string string by replacing them
	with their corresponding values.

	Inputs
	[t_dlist *] envvar: a doubly linked list containing environment variables.
	[char **] str: a string pointer representing the string to be expanded.
	[int *] i: an integer pointer representing the index to track the position
		in the string.
	
	Outputs
	none. the function expands the environment variable in place within the
	string.
*/
void	expand_envvar(t_dlist *envvar, char **str, int *i)
{
	int		length;
	char	*key;
	char	*value;

	key = get_env_key(&str[0][*i + 1]);
	value = get_env_value(envvar, key);
	length = ft_strlen(key);
	ft_replace_substr(str, *i, (*i + length + 1), value);
	free(key);
	*i += ft_strlen(value);
}
