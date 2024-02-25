/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:04:38 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 16:31:36 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

/**
 * @brief Split a string following bash splitting and quoting rules.
 *
 * Splits a string whilst also following bash quoting rules. Strings are split
 * on internal field separators. If multiple IFS are found in a row, these are
 * trimmed.
 *
 * Chars within double quotes are still split. Chars within single quotes are
 * not split. Quotes cause the other quote char to be ignored.
 *
 * Quote ignoring is implemented with a finite state machine.
 * 1: Outside of quotes (splits)
 * 2: Inside double quotes (splits)
 * 3: Inside single quotes (does not split)
 *
 * @param str The string to be split.
 * @return A deque of the words after being split
*/
t_deque	split_word(char *str)
{
	t_deque	result;
	int		slow;
	int		fast;
	int		state;

	result = ft_deque_new();
	split_word_init(&slow, &fast, &state);
	while (str[fast])
	{
		if (state == 1)
		{
			split_word_do_s1(str, &result, &slow, &fast);
			if (str[fast] == '\"')
				state = 2;
			if (str[fast] == '\'')
				state = 3;
		}
		else if (state == 2)
			split_word_do_s2(str[fast], &state);
		else if (state == 3)
			split_word_do_s3(str[fast], &state);
		fast++;
	}
	return (ft_deque_append(&result, ft_strslice(str, slow, fast)), result);
}

/**
 * @brief Split a token node into a list of token nodes with content.str split.
 *
 * Takes in a token node and splits it into a list of token nodes per bash
 * splitting rules.
 *
 * Doesn't split if it doesn't make sense (ie it's an operator type token_node).
 * Splits if it is any other type of token_node (so any token_node that contains
 * a string as content). This /includes/ redirection_word, and
 * redirection_delimiter if you so ask. Which ones to split is handled earlier
 * in the caller "split_token_nodes" to skip these (since they get split later,
 * or never split).
 *
 * If it is not split (either the string is does not need to be split, or the
 * token is an operator type) then it returns the token as the only element of
 * the list (ie a 1 length list).
 *
 * @param token_node The token node to be split.
 * @return A deque with the split nodes in order.
 * @return A NULL deque if a NULL pointer passed in (likely never happens).
 */
t_deque	split_token_node(t_token_node *token_node)
{
	t_deque	split_words ;
	t_dlist	*word_node;
	t_deque	split_token_nodes;

	split_token_nodes = ft_deque_new();
	if (!token_node)
	{
		return (split_token_nodes);
	}
	if (token_node->type == OPERATOR)
	{
		ft_deque_append(&split_token_nodes,
			new_operator_token_node(token_node->content.op));
		return (split_token_nodes);
	}
	split_words = split_word(token_node->content.str);
	word_node = split_words.head;
	while (word_node)
	{
		ft_deque_append(&split_token_nodes,
			new_str_t_n(token_node->type, word_node->content));
		word_node = word_node->next;
	}
	ft_deque_destroy_list(&split_words, free);
	return (split_token_nodes);
}

/**
 * @brief Split words in list of tokens per bash word splitting rules.
 *
 * Taking in a deque of tokens. Splits the words if they should be split.
 * Matches the bash specifications with how it splits. The word splitting occurs
 * if after parameter expansion it "should" be split into separate words (ie. a
 * parameter expansion contains a internal field separator inside of it).
 * Eg. export TEST_VAR="foo bar"; echo $TEST_VAR will split as the two arguments
 * "foo" and "bar", rather than the one argument "foo bar".
 *
 * However, per the specifications, words are only split if they are unquoted.
 * If they are quoted (eg "$TEST_VAR") then it is left unsplit (ie will expand
 * to "foo bar" and be left unsplit).
 *
 * Changes are done in-place in a provided list of tokens.
 *
 * @parameter tokens A list of tokens to split words on.
 */
void	split_token_nodes(t_deque *tokens)
{
	t_deque			new_tokens;
	t_token_node	*token;
	t_deque			split_token;

	new_tokens = ft_deque_new();
	while (1)
	{
		token = ft_deque_popleft(tokens);
		if (!token)
		{
			break ;
		}
		if (token->type == WORD)
		{
			split_token = split_token_node(token);
			ft_deque_append_deque(&new_tokens, split_token);
			delete_token_node(token);
		}
		else
		{
			ft_deque_append(&new_tokens, token);
		}
	}
	tokens->head = new_tokens.head;
	tokens->tail = new_tokens.tail;
}

void	split_words(t_deque *tokens)
{
	split_token_nodes(tokens);
}
