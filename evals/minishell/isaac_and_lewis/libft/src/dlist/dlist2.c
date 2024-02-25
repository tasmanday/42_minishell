/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:39 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 18:00:58 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

/**
 * @brief Pops off an arbitrary node in a dlist
 * 
 * Pops off an arbitrary dlist node from a dlist. 
 * 
 * NB: It assumes that the node is a valid pointer in the list and does not
 * check that this is the case. If the node is not in the dlist then bad things
 * will happen.
 * 
 * @param head The head of the dlist where the node is being popped from.
 * @param node The pointer of the node that is being popped off the list.
 * @return The dlist node that was popped off.
*/
t_dlist	*ft_dlist_pop_at_pointer(t_dlist **head, t_dlist *node)
{
	t_dlist	*popped_node;

	if (node == *head)
	{
		popped_node = ft_dlist_pop_first(head);
		return (popped_node);
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	node->prev->next = node->next;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/**
 * @brief Calculate the length of a dlist
 * 
 * Walks through the dlist and returns the length of the dlist
 * 
 * @param head The head of the dlist.
 * @return The length (number of nodes) in the dlist.
*/
size_t	ft_dlist_length(t_dlist *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
