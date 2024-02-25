/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:47 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:59 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote_removal.h"

/**
 * @brief Checks if the node is empty
 *
 * Takes a dlist node containing a token and returns true (1) or false (0) if
 * the node is empty. A node is empty if it is not a operator type and contains
 * a zero length string.
 *
 * @param node A dlist node that contains a token_node as content.
 * @return 1 If the token->content.str is ""
 * @return 0 If the token->content.str is anything else.
 * @return 0 If the token->type is an operator.
 */
int	node_is_empty(t_dlist *node)
{
	t_token_node	*token;

	token = node->content;
	if (token->type == OPERATOR)
	{
		return (0);
	}
	if (token->type == REDIRECTION_HEREDOC)
	{
		return (0);
	}
	if (ft_strncmp(token->content.str, "", 1) == 0)
	{
		if (token->type != WORD)
		{
			print_err("msh_internal: node_is_empty\n");
			return (1);
		}
		return (1);
	}
	return (0);
}

/**
 * @brief Remove words that are empty from a deque of tokens.
 *
 * Remove the nodes that have a zero length string. These would have been nodes
 * that were expansions that have expanded out to nothing.
 *
 * Per specification: "explicit nulls" are kept. At this stage they would still
 * be quoted so they would be preserved at this time and won't get deleted. (ie
 * they would be the string "" or ''). The quotes will get stripped out later
 * and then be left as preserved null strings.
 *
 * Operates in-place.
 *
 * @param tokens The tokens that will have empty words removed.
 */
void	remove_empty_words(t_deque *tokens)
{
	t_dlist	*old;
	t_dlist	*new;
	t_dlist	*node;

	old = tokens->head;
	node = ft_dlist_pop_first(&old);
	new = NULL;
	while (node)
	{
		if (node_is_empty(node))
		{
			ft_dlist_destroy_node(node, delete_token_node_void);
		}
		else
		{
			ft_dlist_insert_end(&new, node);
		}
		node = ft_dlist_pop_first(&old);
	}
	tokens->head = new;
	tokens->tail = ft_dlist_get_last(new);
}
