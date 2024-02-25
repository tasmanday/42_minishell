/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:45 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 17:53:15 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	is_meta_char(char c)
{
	char	*meta_chars;

	meta_chars = "<>|\'\"";
	if (ft_strchr(meta_chars, c))
		return (true);
	return (false);
}

t_list	*safe_new_node(t_msh *msh, char *str)
{
	t_list	*new_node;

	new_node = lst_new_node(str);
	if (!new_node)
	{
		lst_del_all(&msh->tokens, free_string);
		error_exit("safe_new_node_error");
	}
	return (new_node);
}

void	add_redirection_tokens(t_msh *msh, char *str, int *i)
{
	t_list	*new_node;

	new_node = NULL;
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] == '<')
			new_node = safe_new_node(msh, "<<");
		else
			new_node = safe_new_node(msh, "<");
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] == '>')
			new_node = safe_new_node(msh, ">>");
		else
			new_node = safe_new_node(msh, ">");
	}
	if (new_node)
	{
		lst_add_tail(&(msh->tokens), new_node);
		*i += ft_strlen((char *)new_node->data);
	}
}

void	add_pipe_token(t_msh *msh, char *str, int *i)
{
	t_list	*new_node;

	if (str[*i] == '|')
	{
		new_node = safe_new_node(msh, "|");
		lst_add_tail(&(msh->tokens), new_node);
		*i += 1;
	}
}

void	handle_s_quote_token(t_msh *msh, char *str, int *i)
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
		new_node = safe_new_node(msh, temp_substr);
		lst_add_tail(&(msh->tokens), new_node);
		if (str[*i] == '\'')
			(*i)++;
	}
}

void	handle_d_quote_token(t_msh *msh, char *str, int *i)
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
		new_node = safe_new_node(msh, temp_substr);
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

void	add_tokens_to_list(t_msh *msh, char *str)
{
	int		i;
	int		start;
	char	*temp_substr;
	t_list	*new_node;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (is_meta_char(str[i]))
			handle_meta_chars(msh, str, &i);
		else if (!ft_isprint(str[i]))
			i++;
		else
		{
			start = i;
			while (str[i] && ft_isprint(str[i]) && !is_meta_char(str[i]))
			{
				if (str[i] == '$')
					expand_envvar(msh->envvar, &str, &i);
				else
					i++;
			}
			temp_substr = ft_substr(str, start, i - start);
			if (!temp_substr)
				error("token substr error");
			new_node = safe_new_node(msh, temp_substr);
			lst_add_tail(&(msh->tokens), new_node);
		}
	}
}

void	get_tokens_from_input(t_msh *msh, char **argv)
{
	int		i;

	i = 1; // skips ./minishell

	while (argv[i])
	{
		add_tokens_to_list(msh, argv[i]);
		i++;
	}
}
