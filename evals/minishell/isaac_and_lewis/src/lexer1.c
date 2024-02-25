/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:37 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 16:50:11 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief Void helper for delete_token_node function.
 *
 * Wrapper to allow functions that expect a function of type signature
 * void (*f)(void *) to take in this destructor.
 */
void	delete_token_node_void(void *ptr)
{
	t_token_node	*token;

	token = ptr;
	delete_token_node(token);
}

/**
 * @brief Deletes a token node off the heap.
 *
 * Deletes the token node including any malloced memory inside it.
 */
void	delete_token_node(t_token_node *token)
{
	if (!token)
	{
		return ;
	}
	if (token->type == WORD \
		|| token->type == REDIRECTION_DELIMITER \
		|| token->type == REDIRECTION_WORD)
	{
		free(token->content.str);
	}
	if (token->type == REDIRECTION_HEREDOC)
	{
		close(token->content.fd);
	}
	free(token);
}

/**
 * @brief Creates a new empty token node.
 *
 * Mallocs a new token node and sets all its values to empty values.
 *
 * @return Pointer to a new heap token node
 */
t_token_node	*new_token_node(void)
{
	t_token_node	*ptr;

	ptr = malloc(sizeof(t_token_node) * 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->type = NONE_TYPE;
	ptr->content.str = NULL;
	return (ptr);
}

/**
 * @brief Creates a string new token node with type set and str filled.
 *
 * Constructor for a word (or word like) type of token node. Sets type to the
 * type specified. And allocates a heap string for the content.
 *
 * @return Pointer to the new heap token node.
 */
t_token_node	*new_str_t_n(enum e_token_node_type type, char *str)
{
	t_token_node	*token_ptr;

	token_ptr = new_token_node();
	if (token_ptr == NULL)
	{
		return (NULL);
	}
	token_ptr->type = type;
	token_ptr->content.str = ft_strdup(str);
	return (token_ptr);
}

/**
 * @brief Creates a new operator token node with type set and operator filled.
 *
 * Constructor for a operator type of token node. Sets type to the operator type
 * and sets the content to the corresponding passed in operator value.
 *
 * @return Pointer to the new heap token node.
 */
t_token_node	*new_operator_token_node(enum e_operator op)
{
	t_token_node	*token_ptr;

	token_ptr = new_token_node();
	if (token_ptr == NULL)
	{
		return (token_ptr);
	}
	token_ptr->type = OPERATOR;
	token_ptr->content.op = op;
	return (token_ptr);
}
