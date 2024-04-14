/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:00:49 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:40:35 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
void	create_and_add_token(t_msh *msh, int start, int end)
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
	Summary
	tokenises an argument from the input string and adds it to the token list.

	Inputs
	[t_msh *] msh: a pointer to the main minishell structure.
	[const char *] input: the input string to be tokenized.
	[int *] i: a pointer to the index in the input string.

	Outputs
	none. modifies the token list in the minishell structure.
*/
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

/*
	Summary
	separates tokens from the input string based on whitespace, quotes, and
	redirection symbols.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.
	[const char *] input: the input string to be separated into tokens.

	Outputs
	none. modifies the token list in the minishell structure based on the tokens
	found in the input string.
*/
void	separate_tokens(t_msh *msh, const char *input)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(input);
	while (i < length && input[i])
	{
		check_quotes(msh, input, &i);
		check_redir(msh, input, &i);
		if (!ft_isprint(input[i]) || ft_isspace(input[i]))
			i++;
		else
			tokenise_arg(msh, input, &i);
	}
}

/*
	Summary
	adds tokens to the token list in the minishell structure by processing
	environment variables and separating input into tokens.

	Inputs
	[t_msh *] msh: pointer to the main minishell structure.

	Outputs
	none. modifies the token list in the minishell structure based on the
	processed input.
*/
void	add_tokens_to_list(t_msh *msh)
{
	process_envvars(msh);
	separate_tokens(msh, (const char *)msh->input);
}

/*
	this version of add_tokens_to_lost() will help debug as it will print
	all of the tokens in the list.

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
*/