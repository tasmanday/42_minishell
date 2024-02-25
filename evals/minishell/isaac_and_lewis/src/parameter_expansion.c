/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:35:59 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 22:41:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameter_expansion.h"

/**
 * @brief From a string tries to a parameter key if possible
 *
 * Looks from the head of a string and tries to take any valid parameter.
 * Includes the leading $.
 *
 * Valid parameters are:
 *     A special parameter "?": Will expand to the last exit value
 *     A "number": All chars numbers
 *     A "word": Starts with letter or _ then all chars letters, numbers, or _
 *     A spcial parameter "$": Normally it is a special paramer that resolves to
 *         the current PID. However this is unsupported in msh. Instead warns
 *         the user that this is unsupported behaviour.
 *
 * @param str The string to search through.
 * @return char * New heap string of the parameter.
 * @return char * NULL if no parameter key found.
 */
char	*get_parameter_key(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (str[0] != '$')
		return (NULL);
	if (str[1] == '?')
		return (ft_strdup("$?"));
	if (str[1] == '$')
		return (ft_strdup("$$"));
	i = 1;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		return (ft_strslice(str, 0, i));
	}
	if (ft_isalpha(str[i]) || str[i] == '_')
	{
		while (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		return (ft_strslice(str, 0, i));
	}
	return (ft_strdup("$"));
}

/**
 * @brief Takes a key and searches envv for the parameter.
 *
 * @param str The string key to search for.
 * @param envv The environment to look through.
 * @param last_exit The last exit value (for $? expansion).
 * @return char * A heap string of the resulting parameter.
 * @return char * NULL if no expansion found.
 */
char	*get_parameter_from_key(char *str, char **envv, int last_exit)
{
	char	*result;

	(void)envv;
	if (!str[0])
		return (NULL);
	if (ft_strncmp(str, "$", 2) == 0)
		return (ft_strdup("$"));
	if (ft_strncmp(str, "$?", 3) == 0)
		return (ft_itoa(last_exit));
	if (ft_strncmp(str, "$$", 3) == 0)
		return (ft_strdup("$$"));
	result = msh_getenv(envv, str + 1);
	if (!result)
		return (NULL);
	return (result);
}

/**
 * String expander following shell parameter/env variable rules.
 *
 * Takes a string and searches for a pattern that matches a possible
 * environmental variable and splices in the result.
 *
 * Has to handle quoted environmental variables. Expansion occurs when unquoted
 * or when within double quotes. Does not expand when within single quotes.
 * Quotes of one type cause metacharacters (including the other quote char
 * itself) to be ignored.
 *
 * This functionality is implemented as a finite state machine. The states are:
 * 1: normal mode (expand)
 * 2: inside double quotes (expand)
 * 3: inside single quotes (don't expand)
 *
 * @param str A string to be expanded.
 * @return The expanded string. Returns a zero length heap string even if str
 *     itself is a null pointer.
 * @return NULL only in the event of a malloc error.
 */
void	set_state(size_t *state, char str_j)
{
	if (*state == 1 && str_j == '\"')
	{
		*state = 2;
	}
	else if (*state == 1 && str_j == '\'')
	{
		*state = 3;
	}
	else if (*state == 2 && str_j == '\"')
	{
		*state = 1;
	}
	else if (*state == 3 && str_j == '\'')
	{
		*state = 1;
	}
}

/*
 * @brief: Took out null check for the sake of norm. 
*/
char	*make_expanded_string(char *str, char **envv, int last_exit)
{
	size_t	state;
	size_t	it[2];
	char	*env_key;
	char	*found_param;
	char	*result;

	mes_init(&it[0], &it[1], &state, &result);
	while (str[it[1]])
	{
		if ((state == 1 || state == 2) && str[it[1]] == '$')
		{
			env_key = get_parameter_key(str + it[1]);
			if (env_key)
			{
				mes_do_1(&str, &it[0], &it[1], &result);
				found_param = get_parameter_from_key(env_key, envv, last_exit);
				ft_strappend(&result, found_param);
				mes_do_2(&it[0], &it[1], found_param, env_key);
			}
		}
		else
			set_state(&state, str[it[1]]);
		it[1]++;
	}
	return (mes_do_3(&str, &it[0], &it[1], &result), result);
}

/**
 * @brief Expands the shell parameters within a deque of tokens.
 *
 * When provided with a deque of tokens expands the shell parameters within the
 * strings.
 *
 * Per the bash specification, shell parameters are considered to be a $
 * followed by a name, number or one of the special characters in a particular
 * list. Per our subject, the only special character we need to handle is ?.
 * Therefore, our expansions are:
 *     $<name> - Expands to the value of the env var <name>
 *               Nb. a valid name must start with a letter or an '_' and all
 *               subsequent chars must be alphanumeric or a '_'.
 *               Ie. can not /start/ with a number, then be followed by letters.
 *     $<num>  - All digits
 *     $?      - The most recent exit value
 *
 * Nb. we do not handle ${parameter}, only $parameter (ie we do not handle curly
 * braces) as we have been asked to not consider curly braces as meta
 * characters.
 *
 * We do /not/ handle $$. This is a special parameter that usually expands out
 * to the process id of the shell and not a environment variable expansion.
 *
 * Instead we have chosen to treat $$ as consecutive solo $. And a solo $ bash
 * retains as a $ char in the word.
 *
 * Also to note, shell parameters are expaned when they are inside double quotes
 * but are not expanded when they are inside single quotes. Furthermore,
 * remember that quotes escape other quotes. Therefore:
 *     "'$HOME'" expands (double quotes first) whilst,
 *     '"$HOME"' does not expand (single quotes first).
 * 
 * Also, per the specification, words and words that are redirections are
 * expanded. However, the delimiter of a heredoc is /not/ expanded.
 *
 * Ref:
 * https://www.gnu.org/software/bash/manual/bash.html#Shell-Parameters
 * https://www.gnu.org/software/bash/manual/bash.html#Definitions
 *
 * @param tokens The deque of tokens to work on. Changes are applied in-place
 */
void	expand_tokens(t_deque tokens, char **envv, int last_exit)
{
	t_dlist			*dlist_node;
	t_token_node	*token_node;
	char			*expanded_string;

	dlist_node = tokens.head;
	while (dlist_node)
	{
		token_node = dlist_node->content;
		if (token_node->type == WORD || token_node->type == REDIRECTION_WORD)
		{
			expanded_string = make_expanded_string((token_node->content).str,
					envv, last_exit);
			free(token_node->content.str);
			token_node->content.str = expanded_string;
		}
		dlist_node = dlist_node->next;
	}
}
