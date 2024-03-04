/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:00:49 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 22:08:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	checks if a given character is one of the relavent meta characters.

	Inputs
	[char] c: the character to be checked.

	Outputs
	[bool] true if the character is a meta character, false if it is not.
*/
static bool	is_meta_char(char c)
{
	char	*meta_chars;

	meta_chars = "<>|\'\"";
	if (ft_strchr(meta_chars, c))
		return (true);
	return (false);
}

/*
	Summary
	processes a token and expands any environmental variables present in the
	token string.

	Inputs
	[t_msh *] msh: a pointer to the minishell structure.
	[char *] str: the input string to be processed.
	[int] i: the starting index of the token in the string.

	Outputs
	[int] i: the index value after processing the token and expanding any
		environmental variables.
*/
static int	process_token_and_envvar(t_msh *msh, char *str, int i)
{
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]) \
	&& !is_meta_char(str[i]))
	{
		if (str[i] == '$')
			expand_envvar(msh->envvar, &str, &i);
		else
			i++;
	}
	return (i);
}

/*
	**** ALLOCATES MEMORY ****
	memory allocated for token_str and new_node. token_str is stored in
	new_node->data.

	Summary
	creates a token by extracting a substring from a given string and
	adds it to a linked list.

	Inputs
	[t_msh *] msh: a pointer to the minishell structure.
	[char *] str: the input string from which the token is extracted.
	[int] start: the starting index of the substring.
	[int] end: the ending index of the substring.

	Outputs
	none. The function adds a new token node to the linked list in the msh
	structure.
*/
static void	create_and_add_token(t_msh *msh, char *str, int start, int end)
{
	char	*token_str;
	t_list	*new_node;

	token_str = ft_substr(str, start, end - start);
	if (!token_str)
		error("token_str malloc error");
	new_node = safe_new_token_node(msh, token_str);
	lst_add_tail(&(msh->tokens), new_node);
}

/*
	**** ALLOCATES MEMORY ****
	memory allocated for strings and nodes in msh->tokens linked list.
	responsible sub functions: handle_meta_chars, create_and_add_token.

	Summary
	separates a given string into tokens and adds them to a linked list.
	also handles meta characters and expands environmental variables if
	necessary.

	Inputs
	[t_msh *] msh: a pointer to the minishell structure.
	[char *] str: the input string to be processed.

	Outputs
	none. tokens are added to linked list.
*/
void	add_tokens_to_list(t_msh *msh, char *str)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (is_meta_char(str[i]))
			handle_meta_chars(msh, str, &i);
		else if (!ft_isprint(str[i]) || ft_isspace(str[i]))
			i++;
		else
		{
			start = i;
			i = process_token_and_envvar(msh, str, i);
			create_and_add_token(msh, str, start, i);
		}
	}
}
