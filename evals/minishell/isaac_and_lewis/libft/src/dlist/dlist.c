/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:39 by lxu               #+#    #+#             */
/*   Updated: 2023/08/02 16:55:00 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

/**
 * @brief Create dlist node
 * 
 * Creates a new node of a double neded list.
 * 
 * @param content Content to put into the node.
 * @return Pointer to a new dlist node.
*/
t_dlist	*ft_dlist_new_node(void *content)
{
	t_dlist	*node;

	node = malloc(sizeof (*node) * 1);
	if (!node)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief Destroy dlist node
 * 
 * Destroys a dlist node and it's content using the passed in delete function.
 * 
 * @param node Pointer to the dlist node to be deleted.
 * @param del Delete function to destroy the content.
*/
void	ft_dlist_destroy_node(t_dlist *node, void (*del)(void *))
{
	if (!node | !del)
	{
		return ;
	}
	del(node->content);
	free(node);
	return ;
}

/**
 * @brief Destroy dlist
 * 
 * Walks through a dlist and destroys all the dlist nodes and content. The list
 * is assumed to be homogenous and the content of all nodes can be deleted with
 * the same passed in del function.
 * 
 * @param head Pointer to the first node of the dlist.
 * @param del Delete function to destroy the node content.
*/
void	ft_dlist_destroy_list(t_dlist *head, void (*del)(void *))
{
	t_dlist	*next;

	if (!head | !del)
	{
		return ;
	}
	while (head)
	{
		next = head->next;
		ft_dlist_destroy_node(head, del);
		head = next;
	}
	return ;
}

/**
 * @brief Get last node of a dlist
 * 
 * Walks to the end of a dlist from the node passed in (usually the head node)
 * and returns the pointer to the last node.
 * 
 * @param head Pointer to the first node of the dlist.
 * @returns Pointer to the last node of the dlist.
*/
t_dlist	*ft_dlist_get_last(t_dlist *head)
{
	if (!head)
	{
		return (NULL);
	}
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

/**
 * @brief Remove first node of a dlist
 * 
 * Removes the first node of a dlist and deletes it's content. Then sets the 
 * head pointer to the new head node (the second node) if there is one.
 * Otherwise sets the head to NULL (ie if the dlist had only one node).
 * 
 * @param head Address of the pointer to the first node of the dlist.
 * @param del Delete function to clear the content of the node being deleted.
*/
void	ft_dlist_remove_first(t_dlist **head, void (*del)(void *))
{
	t_dlist	*curr;
	t_dlist	*prev;

	if (!head | !del)
	{
		return ;
	}
	if (!*head)
	{
		return ;
	}
	curr = *head;
	prev = curr;
	curr = curr->next;
	ft_dlist_destroy_node(prev, del);
	if (curr == NULL)
	{
		*head = NULL;
		return ;
	}
	curr->prev = NULL;
	*head = curr;
	return ;
}
