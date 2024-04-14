/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:09:54 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:04:45 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	is_quotes(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* 
	**** ALLOCATES MEMORY ****
	memory allocated for returned string needs to be freed after use.
	
	Summary
	returns a substring that represents the key of an environment variable.

	Inputs
	[char *] str: a pointer to a string that contains an environment variable
		in the format "key=value".

	Outputs
	[char *] a dynamically allocated string that represents the key of the
		environment variable.
*/
char	*get_env_key(char *str)
{
	int		length;

	length = 0;
	while (ft_isprint(str[length]) && !ft_isspace(str[length])
		&& !is_quotes(str[length]))
		length++;
	return (ft_substr(str, 0, length));
}
