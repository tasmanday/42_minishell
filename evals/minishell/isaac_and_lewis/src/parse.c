/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:58:14 by lxu               #+#    #+#             */
/*   Updated: 2023/09/14 12:02:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ast_node	*create_command_ast_node(t_deque d)
{
	t_ast_node	*node;

	node = new_ast_node();
	node->type = AST_CMD;
	node->tokens.head = d.head;
	node->tokens.tail = d.tail;
	return (node);
}

t_ast_node	*create_bracket_ast_node(t_deque *left, t_deque *right)
{
	t_ast_node		*node;
	t_token_node	*token;

	token = ft_deque_popleft(left);
	if (!token || token->type != OPERATOR || token->content.op != LEFT_BRACKET)
	{
		print_err("msh_internal: expecting left bracket token.\n");
		if (token)
		{
			delete_token_node(token);
		}
		ft_deque_destroy_list(left, delete_token_node_void);
		ft_deque_destroy_list(right, delete_token_node_void);
		return (NULL);
	}
	delete_token_node(token);
	node = new_ast_node();
	if (!node)
		return (NULL);
	node->type = AST_BRACKETS;
	node->tokens.head = right->head;
	node->tokens.tail = right->tail;
	node->left = parse_tokens_recursive(*left);
	return (node);
}

t_ast_node	*create_pipe_and_or_ast_node(enum e_operator op, t_deque left,
	t_deque right)
{
	t_ast_node	*node;

	node = new_ast_node();
	if (!node)
	{
		return (NULL);
	}
	if (op == PIPE)
	{
		node->type = AST_PIPE;
	}
	if (op == DOUBLE_AND)
	{
		node->type = AST_AND;
	}
	if (op == DOUBLE_PIPE)
	{
		node->type = AST_OR;
	}
	node->left = parse_tokens_recursive(left);
	node->right = parse_tokens_recursive(right);
	return (node);
}

/**
 * @brief Recursive parse tokens function.
 * 
 * Recursive function call to parse a deque into a AST tree.
 * See parse_tokens_from_deque()
 * 
 * @param d Deque to be parsed
 * @return t_ast_node* AST node for this level
 */
t_ast_node	*parse_tokens_recursive(t_deque d)
{
	t_dlist			*split_loc;
	enum e_operator	op;
	t_deque			left;
	t_deque			right;

	if (ft_deque_length(d) <= 0)
		return (NULL);
	split_loc = tokens_next_split_location(d);
	if (split_loc == NULL)
		return (create_command_ast_node(d));
	op = split_tokens_with_cleanup(&d, &left, &right, split_loc);
	if (op == NONE_OPERATOR)
		return (NULL);
	if (op == RIGHT_BRACKET)
		return (create_bracket_ast_node(&left, &right));
	if (op == PIPE || op == DOUBLE_AND || op == DOUBLE_PIPE)
		return (create_pipe_and_or_ast_node(op, left, right));
	return (NULL);
}

/**
 * @brief Parses a deque of token into a tree of ast nodes.
 * 
 * Consumes the deque of tokens as they are processed. Ie, tokens are deleted as
 * they are parsed.
 * 
 * Recursive descent parser that takes a deque of tokens and converts it into
 * nodes of an abstract syntax tree.
 * 
 * Is "lazy" once it gets to leaf (command) nodes. They are left as lists of
 * tokens which will be converted to a command later. This is to allow parameter
 * substitution if the last_exit value changes (eg "(exit 20) || echo $?" )
 * 
 * Therefore, this parse step only splits on metacharacters and leaves leaf
 * nodes (and the redirection portion of a bracket node) unparsed and stores it
 * for later as a list of tokens in ast_node->tokens.
 * 
 * @param d The deque to be parsed.
 * @return t_ast_node* The head pointer of the parsed AST tree.
 */
t_ast_node	*parse_tokens_from_deque(t_deque *d)
{
	t_ast_node	*head;

	head = parse_tokens_recursive(*d);
	d->head = NULL;
	d->tail = NULL;
	return (head);
}
