/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meta_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:07:01 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 18:18:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	add_redirection_tokens(t_msh *msh, char *str, int *i)
{
	t_list	*new_node;

	new_node = NULL;
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] == '<')
			new_node = safe_new_token_node(msh, "<<");
		else
			new_node = safe_new_token_node(msh, "<");
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] == '>')
			new_node = safe_new_token_node(msh, ">>");
		else
			new_node = safe_new_token_node(msh, ">");
	}
	if (new_node)
	{
		lst_add_tail(&(msh->tokens), new_node);
		*i += ft_strlen((char *)new_node->data);
	}
}

static void	add_pipe_token(t_msh *msh, char *str, int *i)
{
	t_list	*new_node;

	if (str[*i] == '|')
	{
		new_node = safe_new_token_node(msh, "|");
		lst_add_tail(&(msh->tokens), new_node);
		*i += 1;
	}
}

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