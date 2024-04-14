/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:09:54 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:00:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Checks if a character is a quotation mark.

	Inputs
	[char] c: The character to be checked.

	Outputs
	[bool] true if the character is a quotation mark (' or "), otherwise false.
*/
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
