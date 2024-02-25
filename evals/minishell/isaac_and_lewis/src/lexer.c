/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:47:14 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:02:42 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief Clones a token node.
 * 
 * Creates a deep copy clone of a token node.
 * 
 * @param t The node to be cloned.
 * @return t_token_node* THe cloned node.
 */
t_token_node	*clone_token_node(t_token_node *t)
{
	t_token_node	*new_token;

	if (t->type == NONE_TYPE)
	{
		return (new_token_node());
	}
	if (t->type == OPERATOR)
	{
		return (new_operator_token_node(t->content.op));
	}
	if (t->type == WORD || t->type == REDIRECTION_WORD
		|| t->type == REDIRECTION_DELIMITER)
	{
		return (new_str_t_n(t->type, t->content.str));
	}
	if (t->type == REDIRECTION_HEREDOC)
	{
		new_token = new_token_node();
		new_token->type = REDIRECTION_HEREDOC;
		new_token->content.fd = t->content.fd;
		return (new_token);
	}
	return (NULL);
}

/**
 * @brief Creates deque of tokens from a source.
 *
 * Takes in a source and breaks it up into token node that are stored in a
 * linked list in a deque.
 *
 * Follows bash specification.
 * Words are characters separated by any of the following:
 *     Control operators - of which our project subset is ||, &&, |, (, )
 *     Redirection operator - of which our project subset is <, >, <<, >>
 *     Internal field separators - <space char>, <tab char>, <newline char>
 * Of note, it /does not/ split on quote chars, cash char, or question mark,
 * which are expected to be handled by later stages.
 *
 * The reason for this is so that some edge cases behave correctly. Eg
 * hello"world" is not the two args "hello" and "world". But is the single arg
 * "helloworld".
 *
 * While doing the splitting, operators become operator nodes. IFS chars are
 * discarded. Words are all other chars in between.
 *
 * Words are mostly identical, however there are two special types.
 * REDIRECTION_DELIMITER - A word following the heredoc redirection operator.
 * REDIRECTION_WORDS - A word following any other redirection operator.
 *
 * This is done because whilst words are mostly processed the same. A few small
 * differences exist and therefore a heredoc delimiter and a redirection word
 * must keep a note that they are such so that they get processed differently.
 *
 * @param src The new source struct to work with.
 * @return A deque with a linked list of tokens in order.
 */

void	stt_do(t_source *src, t_deque *tokens_pt)
{
	t_token_node	*token;
	t_deque			tokens;
	char			*word;
	enum e_operator	op;

	tokens = *tokens_pt;
	op = NONE_OPERATOR;
	token = NULL;
	if (tokens.tail)
		token = (t_token_node *)(tokens.tail->content);
	if (token && token->type == OPERATOR)
		op = token->content.op;
	word = take_word(src);
	if (op == DOUBLE_LESS_THAN)
		ft_deque_append(&tokens, new_str_t_n(REDIRECTION_DELIMITER, word));
	else if (op == LESS_THAN || op == GREATER_THAN
		|| op == DOUBLE_GREATER_THAN)
		ft_deque_append(&tokens, new_str_t_n(REDIRECTION_WORD, word));
	else
		ft_deque_append(&tokens, new_str_t_n(WORD, word));
	free(word);
	*tokens_pt = tokens;
}
//potential leak above.

t_deque	source_to_tokens(t_source *src)
{
	t_deque			tokens;

	tokens = ft_deque_new();
	while (1)
	{
		skip_internal_field_separators(src);
		if (peek_char(src) == '\0')
			return (tokens);
		if (operator_is_next(src))
			ft_deque_append(&tokens,
				new_operator_token_node(take_operator(src)));
		else
		{
			stt_do(src, &tokens);
		}
	}
}
