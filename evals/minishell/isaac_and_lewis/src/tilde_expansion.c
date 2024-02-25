/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:41 by lxu               #+#    #+#             */
/*   Updated: 2023/09/11 20:09:09 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tilde_expansion.h"

/**
 * @brief Gets the tilde prefix string.
 *
 * The tilde prefix string is all the characters up to the first unquoted slash.
 *
 * eg if string is ~"hello"world/path/to/something
 * the tilde prefix would be "hello"world
 *
 * FSM to check quotes
 * 1 - normal (outside quotes)
 * 2 - inside dquotes
 * 3 - inside squotes
 *
 * @param str The string to try to pull out the tilde string.
 * @return The tilde string.
 */
char	*get_tilde_prefix_str(char *str)
{
	size_t	i;
	int		state;

	if (!str || str[0] != '~')
	{
		return (ft_strdup(""));
	}
	i = 1;
	state = 1;
	while (str[i])
	{
		if (state == 1 && str[i] == '/')
			break ;
		else if (state == 1 && str[i] == '\"')
			state = 2;
		else if (state == 1 && str[i] == '\'')
			state = 3;
		else if (state == 2 && str[i] == '\"')
			state = 1;
		else if (state == 3 && str[i] == '\'')
			state = 1;
		i++;
	}
	return (ft_strslice(str, 1, i));
}

void	get_strings(char **home_str, char **user_str, char **envv)
{
	*home_str = msh_getenv(envv, "HOME");
	*user_str = msh_getenv(envv, "USER");
}

/**
 * @brief Tilde expansion of a string.
 *
 * Does tilde expansion similar to bash. Only does a subset of the bash tilde
 * expansions. Also, doesn't quite handle "the home directory of the user" as
 * in our allowed functions we have no way of getting the home directory of a
 * user xyz. Therefore it is presumed to be at /Users/xyz
 *
 * If first char is a tilde all characters up to the first unquoted slash forms
 * the tilde-prefix.
 *
 * If tilde_prefix is quoted: tilde_prefix has quotes removed. Otherwise word is
 * left unchanged.
 *
 * If none of the characters in tilde_prefix are quoted, it is then considered a
 * possible login_name.
 *
 * If login_name is a null string: the tilde is replaced with the HOME shell
 * variable.
 *
 * If HOME is unset: the home directory of the user executing the shell is
 * substituted instead (manually set to be /Users/$USER since we can't get the
 * actual home directory in our allowed functions).
 *
 * If login_name is a valid login: tilde is set to that user's home directory.
 * As above, it is manually set to be /Users/$USER Also since we can't actually
 * check for the existance of other users the only user it passes is the the
 * user saved in $USER.
 *
 * Otherwise, login_name is invalid: the word is left unchanged.
 *
 * @param str String to tilde expand.
 * @param envv The current environment variables.
 * @return char * The tilde expanded string.
 */
char	*tilde_expand_string(char *str, char **envv)
{
	char	*login_name;
	char	*user_str;
	char	*home_str;
	char	*expanded_str;
	size_t	prefix_len;

	if (!str || str[0] != '~')
		return (ft_strdup(str));
	login_name = get_tilde_prefix_str(str);
	get_strings(&home_str, &user_str, envv);
	if (!home_str)
		home_str = ft_strjoin("/Users/", user_str);
	if (str_has_quote_char(login_name))
	{
		prefix_len = ft_strlen(login_name);
		remove_quotes_string(login_name);
		expanded_str = ft_strconcat(3, "~", login_name, str + 1 + prefix_len);
	}
	if (!login_name || login_name[0] == '\0')
		expanded_str = ft_strjoin(home_str, str + 1);
	else if (ft_strncmp(user_str, login_name, ft_strlen(login_name + 1)) == 0)
		expanded_str = ft_strjoin(home_str, str + 1 + ft_strlen(login_name));
	else
		expanded_str = ft_strdup(str);
	return (free(login_name), free(home_str), free(user_str), expanded_str);
}

/**
 * @brief Perform tilde expansion on a deque of tokens.
 *
 * @param tokens The tokens to tilde expand.
 * @parm envv The environment variables.
 */
void	tilde_expand_tokens(t_deque tokens, char **envv)
{
	t_dlist			*dlist_node;
	t_token_node	*token_node;
	char			*expanded_str;

	dlist_node = tokens.head;
	while (dlist_node)
	{
		token_node = dlist_node->content;
		if (token_node->type == WORD || token_node->type == REDIRECTION_WORD)
		{
			expanded_str = tilde_expand_string(token_node->content.str, envv);
			free(token_node->content.str);
			token_node->content.str = expanded_str;
		}
		dlist_node = dlist_node->next;
	}
}
