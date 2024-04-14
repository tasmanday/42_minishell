/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meta_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:07:01 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:20:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	checks and updates the state based on if the current character in the input
	string is a single or souble quote. used by process_envvars() to know which
	environmental variables should be expanded. 

	Inputs
	[char] current_char: the current character being processed.
	[int *] state: pointer to the state variable to be updated.

	Outputs
	none. updates the state variable based on the current character.
*/
static void	check_state(char current_char, int *state)
{
	if (*state == 0)
	{
		if (current_char == '\'')
			*state = 1;
		else if (current_char == '\"')
			*state = 2;
	}
	else if (*state == 1 && current_char == '\'')
		*state = 0;
	else if (*state == 2 && current_char == '\"')
		*state = 0;
}

/*
	Summary
	processes environment variables in the input string and expands them
	depending on if they are in single or double quotes or no quotes at all.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.

	Outputs
	none. modifies the input string by expanding environment variables.
*/
void	process_envvars(t_msh *msh)
{
	int		state;
	int		i;

	i = 0;
	state = 0;
	while (msh->input[i])
	{
		check_state(msh->input[i], &state);
		if ((state == 0 || state == 2) && msh->input[i] == '$')
			expand_envvar(msh, &i);
		else
			i++;
	}
}

/*
	Summary
	checks for quoted strings (single or double quotes) in the input string and
	adds corresponding tokens to the token list.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.
	[const char *] input: the input string to be checked for quoted strings.
	[int *] i: pointer to the index in the input string.

	Outputs
	none. modifies the token list in the minishell structure based on the quoted
	strings found in the input string.
*/
void	check_quotes(t_msh *msh, const char *input, int *i)
{
	int		start;
	int		end;
	char	quote;

	if (input[*i] == '\'' || input[*i] == '\"')
	{
		start = *i + 1;
		quote = input[*i];
		(*i)++;
		while (input[*i] != quote)
			(*i)++;
		end = *i;
		create_and_add_token(msh, start, end);
		(*i)++;
	}
	return ;
}

/*
	Summary
	checks for redirection symbols ('|', '<', '>') in the input string and adds
	corresponding tokens to the token list.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.
	[const char *] input: the input string to be checked for redirection symbols.
	[int *] i: pointer to the index in the input string.

	Outputs
	none. modifies the token list in the minishell structure based on the
	redirection symbols found in the input string.
*/
void	check_redir(t_msh *msh, const char *input, int *i)
{
	if (input[*i] == '|')
	{
		create_and_add_token(msh, *i, *i + 1);
		(*i)++;
	}
	else if (input[*i] == '<' || input[*i] == '>')
	{
		if (input[*i] == input[*i + 1])
		{
			create_and_add_token(msh, *i, *i + 2);
			*i += 2;
		}
		else
		{
			create_and_add_token(msh, *i, *i + 1);
			(*i)++;
		}
	}
	return ;
}

/*
	Summary
	checks if a character is a valid argument character.

	Inputs
	[char] c: the character to be checked.

	Outputs
	[bool] true if the character is valid for an argument, otherwise false.
*/
bool	is_valid_arg_char(char c)
{
	char	*invalid_chars;

	invalid_chars = "<>|\'\"";
	if (ft_strchr(invalid_chars, c))
		return (false);
	else if (!ft_isprint(c) || ft_isspace(c))
		return (false);
	else
		return (true);
}
