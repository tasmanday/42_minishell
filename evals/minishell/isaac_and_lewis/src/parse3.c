/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:58:14 by lxu               #+#    #+#             */
/*   Updated: 2023/09/14 12:04:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	set_left_empty(t_deque *source, t_deque *left, t_deque *right)
{
	right->head = source->head;
	right->tail = source->tail;
	left->head = NULL;
	left->tail = NULL;
}

void	set_split_deques(t_deque *source, t_deque *left, t_deque *right,
	t_dlist *split_loc)
{
	left->head = source->head;
	left->tail = split_loc->prev;
	right->head = split_loc;
	right->tail = source->tail;
	left->tail->next = NULL;
	right->head->prev = NULL;
}

/**
 * @brief Splits a deque of tokens at the index specified by the split location
 * 
 * Operation occurs in place.
 * 
 * Takes a source deque. Splits it at the node split_loc into it's left and
 * right halves with the centre node being put into centre.
 * 
 * @param source The original deque to be split.
 * @param left The deque to the left of the split location.
 * @param right The deque to the right of the split location.
 * @param split_loc The location to be split.
 * @return t_token_node *centre The content of the node split_loc
 *						NULL if no split or error.
 */
t_token_node	*split_tokens(t_deque *source, t_deque *left, t_deque *right,
	t_dlist *split_loc)
{
	t_dlist			*node;
	t_token_node	*centre;

	if (!source || !left || !right || !split_loc)
		return (print_err("msh_internal: split tokens\n"), NULL);
	node = source->head;
	while (node)
	{
		if (node == split_loc)
			break ;
		if (node == NULL)
			return (print_err("msh_internal: Unable to split tokens.\n"), NULL);
		node = node->next;
	}
	if (split_loc == source->head)
		set_left_empty(source, left, right);
	else
		set_split_deques(source, left, right, split_loc);
	source->head = NULL;
	source->tail = NULL;
	centre = ft_deque_popleft(right);
	return (centre);
}

enum e_operator	split_tokens_with_cleanup(t_deque *source, t_deque *left,
	t_deque *right, t_dlist *split_loc)
{
	t_token_node	*token;
	enum e_operator	op;

	*left = ft_deque_new();
	*right = ft_deque_new();
	token = split_tokens(source, left, right, split_loc);
	if (!token || token->type == WORD || token->type == REDIRECTION_WORD
		|| token->type == REDIRECTION_DELIMITER)
	{
		print_err("msh_internal: found unexpected token when parsing. Bug?\n");
		delete_token_node(token);
		ft_deque_destroy_list(source, delete_token_node_void);
		ft_deque_destroy_list(left, delete_token_node_void);
		ft_deque_destroy_list(right, delete_token_node_void);
		return (NONE_OPERATOR);
	}
	op = token->content.op;
	delete_token_node(token);
	return (op);
}
