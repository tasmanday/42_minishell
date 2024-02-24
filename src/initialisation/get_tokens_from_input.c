/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:45 by tday              #+#    #+#             */
/*   Updated: 2024/02/24 15:01:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_meta_char(char c)
{
	char	*meta_chars;

	meta_chars = "<>|\'\"";
	if (ft_strchr(meta_chars, c))
		return (true);
	return (false);
}

// make handle_meta_chars()

void	add_tokens_to_list(t_msh *msh, char *str)
{
	int		i;
	int		start;
	char	*temp_substr;

	i = 0;
	start = 0;
	while(str[i])
	{
		if (is_meta_char(str[i]))
			handle_meta_chars(str, &i);
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
			//add temp_substr to t_list
		}
	}
}

void	get_tokens_from_input(t_msh *msh, char **argv)
{
	int		i;

	i = 1;

	while (argv[i])
	{
		add_tokens_to_list(msh, argv[i]);
	}
}