/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:00:49 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 18:18:34 by tday             ###   ########.fr       */
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
			new_node = safe_new_token_node(msh, temp_substr);
			lst_add_tail(&(msh->tokens), new_node);
		}
	}
}