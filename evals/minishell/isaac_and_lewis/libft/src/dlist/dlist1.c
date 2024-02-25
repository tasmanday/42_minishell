/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:39 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 18:00:41 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

/**
 * @brief Remove the last node of a dlist
 * 
 * Walks to the end of a dlist and deletes the last node.
 * 
 * @see ft_dlist_remove_first()
 * @param head Address of the pointer to the head of the dlist.
 * @param del Delete function to clear the content of the node being deleted.
*/
void	ft_dlist_remove_last(t_dlist **head, void (*del)(void *))
{
	t_dlist	*last;
	t_dlist	*prev;

	if (!head | !del)
	{
		return ;
	}
	if (!*head)
	{
		return ;
	}
	last = ft_dlist_get_last(*head);
	prev = last->prev;
	ft_dlist_destroy_node(last, del);
	if (prev == NULL)
	{
		*head = NULL;
		return ;
	}
	prev->next = NULL;
	return ;
}

/**
 * @brief Insert a node at the start of a dlist
 * 
 * Inserts a dlist node to the start of a dlist. Then updates the head pointer
 * to point to the new head (the newly inserted node).
 * 
 * @param head Address of the pointer to the first node of the dlist.
 * @param new_node Pointer to the new node to be inserted.
*/
void	ft_dlist_insert_start(t_dlist **head, t_dlist *new_node)
{
	if (!head | !new_node)
	{
		return ;
	}
	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = *head;
	new_node->prev = NULL;
	(*head)->prev = new_node;
	*head = new_node;
	return ;
}

/**
 * @brief Insert a node at the end of a dlist
 * 
 * Inserts a dlist node to the end of a dlist. Then updates the head pointer if
 * the head pointer needs to be updated (if the head pointer was previously
 * NULL and the new node is now the only node).
 * 
 * @param head Address of the pointer to the first node of the dlist.
 * @param new_ndoe Pointer to the new node to be inserted.
*/
void	ft_dlist_insert_end(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*last;

	if (!head | !new_node)
	{
		return ;
	}
	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	last = ft_dlist_get_last(*head);
	last->next = new_node;
	new_node->next = NULL;
	new_node->prev = last;
	return ;
}

/**
 * @brief Pop and return the first element of a dlist
 * 
 * Pops off the first element of a dlist and returns it. Modifies the head
 * pointer to point to the new head node (the second node). Pointer is set to
 * NULL if there are no remaining nodes in the dlist.
 * 
 * @param head Address of the pointer to the head of the dlist.
 * @return dlist node that has been popped off.
*/
t_dlist	*ft_dlist_pop_first(t_dlist **head)
{
	t_dlist	*node;

	if (!head)
	{
		return (NULL);
	}
	if (!*head)
	{
		return (NULL);
	}
	node = *head;
	*head = (*head)->next;
	node->next = NULL;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	return (node);
}

/**
 * @brief Pop and return the last element of a dlist
 * 
 * Pops off the last element of a dlist and returns it. Modifies the head
 * pointer of the dlist if it needs to be updated.
 * 
 * @param head Address of the pointer to the head of the dlist.
 * @return dlist node that has been popped off.
*/
t_dlist	*ft_dlist_pop_last(t_dlist **head)
{
	t_dlist	*node;

	if (!head)
	{
		return (NULL);
	}
	if (!*head)
	{
		return (NULL);
	}
	node = ft_dlist_get_last(*head);
	if (node->prev == NULL)
	{
		*head = NULL;
	}
	else
	{
		node->prev->next = NULL;
	}
	node->prev = NULL;
	return (node);
}
