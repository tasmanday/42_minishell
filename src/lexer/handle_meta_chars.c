/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meta_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:07:01 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 15:46:55 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for a linked list node in safe_new_token_node function.

	Summary
	adds redirection tokens to msh->tokens based on the current character in
	the input string.

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.
	[char *] str: the input string to be processed.
	[int *] i: a pointer to the index variable.

	Outputs
	none. the function modifies the minishell structure by adding tokens to the
	msh->tokens linked list.
*/
static void	add_redirection_tokens(t_msh *msh, char *str, int *i) 
{
	t_list	*new_node;
	char	*temp_str;

	new_node = NULL;
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] == '<')
		{
			temp_str = ft_substr(str, (*i), 2);
			new_node = safe_new_token_node(msh, temp_str);
			*i += 2;
		}
		else
		{
			temp_str = ft_substr(str, (*i), 1);
			new_node = safe_new_token_node(msh, temp_str);
			*i += 1;
		}
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] == '>')
		{
			temp_str = ft_substr(str, (*i), 2);
			new_node = safe_new_token_node(msh, temp_str);
			*i += 2;
		}
		else
		{
			temp_str = ft_substr(str, (*i), 1);
			new_node = safe_new_token_node(msh, temp_str);
			*i += 1;
		}
	}
	if (new_node)
	{
		lst_add_tail(&(msh->tokens), new_node);
	}
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for a linked list node in safe_new_token_node function.

	Summary
	adds a pipe token to msh->tokens if the current character in the input
	string is a pipe symbol ('|').

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.
	[char *] str: the input string to be processed.
	[int *] i: a pointer to the index variable.

	Outputs
	none. the function modifies the minishell structure by adding tokens to the
	msh->tokens linked list.
*/
static void	add_pipe_token(t_msh *msh, char *str, int *i)
{
	t_list	*new_node;
	char 	*temp_str;

	if (str[*i] == '|')
	{
		temp_str = ft_substr(str, (*i), 1);
		new_node = safe_new_token_node(msh, temp_str);
		lst_add_tail(&(msh->tokens), new_node);
		*i += 1;
	}
}

/*
	**** ALLOCATES MEMORY ****
	memory allocated for token_str and new_node. token_str is stored in
	new_node->data.
	
	Summary
	handles single quote tokens in a given string by extracting the substring
	between the single quotes and adding it as a new token to msh->tokens.

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.
	[char *] str: the input string to be processed.
	[int *] i: a pointer to the index variable.

	Outputs
	none. the function modifies the minishell structure by adding tokens to the
	msh->tokens linked list.
*/
static void	handle_s_quote_token(t_msh *msh, char *str, int *i)
{
	int		start;
	char	*temp_substr;
	t_list	*new_node;

	if (str[*i] == '\'')
	{
		(*i)++;
		start = *i;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
		temp_substr = ft_substr(str, start, (*i) - start);
		if (!temp_substr)
			error("s_quote substr error");
		new_node = safe_new_token_node(msh, temp_substr);
		lst_add_tail(&(msh->tokens), new_node);
		if (str[*i] == '\'')
			(*i)++;
	}
}

/*
	**** ALLOCATES MEMORY ****
	memory allocated for token_str and new_node. token_str is stored in
	new_node->data.

	Summary
	handles double quote tokens in a given string by extracting the substring
	between the double quotes and adding it as a new token to msh->tokens.

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.
	[char *] str: the input string to be processed.
	[int *] i: a pointer to the index variable.

	Outputs
	none. the function modifies the minishell structure by adding tokens to the
	msh->tokens linked list.
*/
static void	handle_d_quote_token(t_msh *msh, char *str, int *i)
{
	int		start;
	char	*temp_substr;
	t_list	*new_node;

	if (str[*i] == '\"')
	{
		(*i)++;
		start = *i;
		while (str[*i] && str[*i] != '\"')
		{
			if (str[*i] == '$')
				expand_envvar(msh->envvar, &str, i);
			else
				(*i)++;
		}
		temp_substr = ft_substr(str, start, (*i) - start);
		if (!temp_substr)
			error("s_quote substr error");
		new_node = safe_new_token_node(msh, temp_substr);
		lst_add_tail(&(msh->tokens), new_node);
		if (str[*i] == '\"')
			(*i)++;
	}
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for linked list nodes in sub functions

	Summary
	handles meta characters in a given string by calling different helper
	functions based on the character encountered.

	Inputs
	[t_msh *] msh: a pointer to the minishell main structure.
	[char *] str: the input string to be processed.
	[int *] i: a pointer to the index variable.

	Outputs
	none. the function modifies the minishell structure by adding tokens to the
	msh->tokens linked list.
*/
void	handle_meta_chars(t_msh *msh, char *str, int *i)
{
	if (str[*i] == '<' || str[*i] == '>')
		add_redirection_tokens(msh, str, i);
	else if (str[*i] == '|')
		add_pipe_token(msh, str, i);
	else if (str[*i] == '\'')
		handle_s_quote_token(msh, str, i);
	else if (str[*i] == '\"')
		handle_d_quote_token(msh, str, i);
	else
		return ;
}
