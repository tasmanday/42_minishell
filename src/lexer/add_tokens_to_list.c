/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:00:49 by tday              #+#    #+#             */
/*   Updated: 2024/04/07 19:54:49 by tday             ###   ########.fr       */
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
/* static bool	is_meta_char(char c)
{
	char	*meta_chars;

	meta_chars = "<>|\'\"";
	if (ft_strchr(meta_chars, c))
		return (true);
	return (false);
} */

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
/* static int	process_token_and_envvar(t_msh *msh, char **str, int i)
{
	while ((*str)[i] && ft_isprint((*str)[i]) && !ft_isspace((*str)[i]) \
	&& !is_meta_char((*str)[i]))
	{
	
		if ((*str)[i] == '$')
			expand_envvar(msh->envvar, str, &i);
		else
			i++;
	}
	return (i);
} */

/*
	**** ALLOCATES MEMORY ****
	memory allocated for token_str and new_node. token_str is stored in
	new_node->data.

	Summary
	creates a token by extracting a substring from a given string and
	adds it to a linked list.

	Inputs
	[t_msh *] msh: a pointer to the minishell structure.
	[int] start: the starting index of the substring.
	[int] end: the ending index of the substring.

	Outputs
	none. The function adds a new token node to the linked list in the msh
	structure.
*/
static void	create_and_add_token(t_msh *msh, int start, int end)
{
	char	*token_str;
	t_list	*new_node;

	token_str = ft_substr(msh->input, start, end - start);
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
/* void	add_tokens_to_list(t_msh *msh, char *str)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (is_meta_char(str[i]))
		{
			handle_meta_chars(msh, str, &i);
			continue ;
		}
		else if (!ft_isprint(str[i]) || ft_isspace(str[i]))
			i++;
		else
		{
			start = i;
			i = process_token_and_envvar(msh, &str, i);
			create_and_add_token(msh, str, start, i);
		}
	}
	t_list	*curr = msh->tokens;
	while (curr)
	{
		printf("token: %s\n", (char *)curr->data);
		curr = curr->next;
	}
//	free(str);
} */

void	check_state(char current_char, int *state)
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

/* void	add_opp_token(t_msh *msh, int *i)
{
	if (msh->input[*i] != '|' && (msh->input[*i] == msh->input[*i + 1]))
		{
			create_and_add_token(msh, *i, *i + 2);
			*i += 2;
		}
	else
		{
			create_and_add_token(msh, *i, *i + 1);
			*i += 1;
		}
} */

/* void	handle_no_quotes(t_msh *msh)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	start = 0;
	str = msh->input;
	while (str[i])
	{
		if (!ft_isprint(str[i]) || ft_isspace(str[i]))
			i++;
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
		{
			add_opp_token(msh, &i);
		}
		else //add tokens 
		{
			start = i;
			while (is_valid)
				i++;
				create_and_add_token(msh, start, i);
		}
	}
} */
/*
	if (ft_strchr(msh->input, 34) || ft_strchr(msh->input, 39)) //might be able to just process the string in one go and check for quotes as we go
		handle_quotes(msh);
	else
		handle_no_quotes(msh);
*/

void	check_quotes(t_msh *msh, const char *input, int *i)
{
	int		start;
	int		end;
	char		quote;
	
	if (input[*i] == '\'' || input[*i] == '\"')
	{
		start = *i + 1; // might need to be +1
		quote = input[*i];
		(*i)++;
		while (input[*i] != quote)
			(*i)++;
		end = *i; // might need to be +1
		create_and_add_token(msh, start, end);
		(*i)++; // possibly remove
	}
	return ;
}

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

static bool	is_valid_arg_char(char c)
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

void	tokenise_arg(t_msh *msh, const char *input, int *i)
{
	int		start;
	int		end;

	if (is_valid_arg_char(input[*i]))
	{
		start = *i;
		(*i)++;
		while (is_valid_arg_char(input[*i]))
			(*i)++;
		end = *i;
		create_and_add_token(msh, start, end);
	}
}

void	separate_tokens(t_msh *msh, const char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		check_quotes(msh, input, &i);
		check_redir(msh, input, &i);
		if (!ft_isprint(input[i]) || ft_isspace(input[i]))
			i++;
		else
			tokenise_arg(msh, input, &i);
	}
}

void	add_tokens_to_list(t_msh *msh)
{
	process_envvars(msh);
	separate_tokens(msh, (const char *)msh->input);
	t_list	*curr = msh->tokens; //
	int	i = 0; //
	while (curr) //
	{ //
		printf("token %i: %s\n", i, (char *)curr->data); //
		i++; //
		curr = curr->next; //
	} //
}
