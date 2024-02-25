/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:30:14 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 12:28:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

/**
 * @brief Creates a list of redirections from a deque of tokens.
 * 
 * Consumes a deque of tokens and converts it into a list of redirections.
 * Assumes that the list is purely redirections and there are no other token
 * types within.
 * 
 * Used only for brackets to handle the redirections post brackets. ie:
 * (list) > out1.txt <in1.txt >>etc.txt
 * 
 * In this situation, the syntax checker should have already made sure that
 * there will be no other token types.
 * 
 * @param t The tokens to consume.
 * @return t_list* A linked list of redirections.
 */
int	ttrl_check_1(t_token_node *token)
{
	if (token->type == OPERATOR
		&& (token->content.op == LESS_THAN
			|| token->content.op == DOUBLE_LESS_THAN
			|| token->content.op == GREATER_THAN
			|| token->content.op == DOUBLE_GREATER_THAN))
		return (1);
	return (0);
}

int	ttrl_check_2(t_token_node *token)
{
	if (token->type != REDIRECTION_WORD
		&& token->type != REDIRECTION_DELIMITER
		&& token->type != REDIRECTION_HEREDOC)
		return (1);
	return (0);
}

void	ttrl_do2(t_redirection **redirection_pt, t_token_node *token)
{
	t_redirection	*redirection;

	redirection = *redirection_pt;
	if (token->type == REDIRECTION_HEREDOC)
	{
		redirection->file_name = ft_strdup("");
		redirection->old_fd = 0;
		redirection->new_fd = dup(token->content.fd);
	}
	else
		redirection->file_name = ft_strdup(token->content.str);
}

int	ttrl_do1(t_token_node **token_pt, t_redirection **redirection_pt,
		t_deque *t, t_list **list_node_pt)
{
	t_token_node	*token;
	t_redirection	*redirection;
	t_list			*list_node;

	token = *token_pt;
	redirection = *redirection_pt;
	list_node = *list_node_pt;
	if (!redirection)
		return (1);
	token = ft_deque_popleft(t);
	if (!token)
		return (1);
	if (ttrl_check_2(token))
		return (1);
	ttrl_do2(&redirection, token);
	delete_token_node(token);
	list_node = ft_lstnew(redirection);
	if (!list_node)
	{
		delete_redirection(redirection);
		return (1);
	}
	*token_pt = token;
	*list_node_pt = list_node;
	return (0);
}

t_list	*tokens_to_redirection_list(t_deque *t)
{
	t_redirection	*redirection;
	t_token_node	*token;
	t_list			*redirections_head;
	t_list			*list_node;

	redirections_head = NULL;
	list_node = NULL;
	while (1)
	{
		token = ft_deque_popleft(t);
		if (!token)
			break ;
		if (ttrl_check_1(token))
		{
			redirection = new_redirection_with_type_from_op(token->content.op);
			delete_token_node(token);
			if (ttrl_do1(&token, &redirection, t, &list_node))
				break ;
			ft_lstadd_back(&redirections_head, list_node);
		}
		else
			break ;
	}
	ft_deque_destroy_list(t, delete_token_node_void);
	return (redirections_head);
}
