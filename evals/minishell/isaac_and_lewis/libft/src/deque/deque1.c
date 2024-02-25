/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:37 by lxu               #+#    #+#             */
/*   Updated: 2023/08/09 17:18:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

/**
 * @brief Pop first element of a deque
 * 
 * Pops and returns the content of the first element of the deque.
 * 
 * @see ft_deque_append()
 * @see ft_deque_pop()
 * @param d Pointer to the deque to pop from.
 * @return The void pointer to the content that was in the node.
*/
void	*ft_deque_popleft(t_deque *d)
{
	t_dlist	*node;
	void	*content;
	t_dlist	*next_node;

	if (!d)
	{
		return (NULL);
	}
	if (d->head == NULL)
	{
		return (NULL);
	}
	next_node = d->head->next;
	node = ft_dlist_pop_first(&d->head);
	content = node->content;
	d->head = next_node;
	free(node);
	if (d->head == NULL)
	{
		d->tail = NULL;
	}
	return (content);
}

/**
 * @brief Calculate the length of a deque
 * 
 * Calculates the number of nodes in the deque.
 * 
 * @param d The deque to find the length of.
 * @return The length of the deque.
*/
size_t	ft_deque_length(t_deque d)
{
	return (ft_dlist_length(d.head));
}
