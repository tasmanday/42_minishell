/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:50:08 by tday              #+#    #+#             */
/*   Updated: 2024/02/19 20:50:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

typedef enum	e_quote
{
	no_quotes,
	single_quotes,
	double_quotes,
	both_quotes,
}				t_quote;

char	*ft_get_env_key(char *str)
{
	int 	length;

	length = 0;
	while (ft_isalnum(str[length]) || str[length] == '_')
		length++;
	return (ft_substr(str, 0, length));
}

char	*ft_get_env_value(t_dlist *envvar, char * key)
{
	t_dlist *node;
	t_envv	*envv_struct;

	node = find_envvar_node(envvar, key);
	envv_struct = (t_envv *)node->data;
	return (envv_struct->env_value);
}

void	expand_envvar(t_dlist *envvar, char **str)
{
	int		i;
	int		length;
	char	*key;
	char	*value;
	char	*modified;
	
	i = 0;
	key = NULL;
	while (str[0][i])
	{
		if (str[0][i] == '$')
			{
				key = ft_get_env_key(str[0][i]);
				value = ft_get_env_value(envvar, key);
				length = ft_strlen(key);
				//ft_replace_substr()
			}
		i++;
	}
}
