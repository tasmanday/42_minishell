/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:37 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 18:00:28 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

/**
 * @brief Create new deque
 * 
 * Create new deque and sets the starting values to NULL.
 * 
 * @return New deque.
*/
t_deque	ft_deque_new(void)
{
	t_deque	d;

	d.head = NULL;
	d.tail = NULL;
	return (d);
}

/**
 * @brief Destroys a deque
 * 
 * Destroys a deque. A delete function is passed in to destroy the contents of
 * the deque/list nodes.
 * 
 * @param d Pointer to the deque to destroy.
 * @param del Delete function that is used to clear the list node contents.
*/
void	ft_deque_destroy_list(t_deque *d, void (*del)(void *))
{
	ft_dlist_destroy_list(d->head, del);
	d->head = NULL;
	d->tail = NULL;
}

/**
 * @brief Append content to the end of a deque
 * 
 * Takes a pointer to some content and appends it to the end of the deque. Then
 * modifies the deque nodes appropriately.
 * 
 * Design choice: appending and popping expects and returns the content void ptr
 *   rather than the dlist node itself.
 * Advantage: No need to remember to create and breakdown the intermediary dlist
 *   nodes.
 * Disadvantage: Moving an element from bottom to top (or vice versa) involves a
 *   free then malloc of a node rather than moving the node directly.
 * 
 * @param d Pointer to the deque to append to.
 * @param content Pointer to the content to be added.
*/
void	ft_deque_append(t_deque *d, void *content)
{
	t_dlist	*node;

	node = ft_dlist_new_node(content);
	if (!node)
	{
		return ;
	}
	ft_dlist_insert_end(&d->tail, node);
	if (d->head == NULL)
	{
		d->head = node;
	}
	d->tail = node;
}

/**
 * @brief Prepend content to the start of a deque
 * 
 * Takes a pointer to some content and prepends it to the start of the deque.
 * 
 * @see ft_deque_append()
 * @param d Pointer to the deque to prepend to.
 * @param content Pointer to the content to be added.
*/
void	ft_deque_appendleft(t_deque *d, void *content)
{
	t_dlist	*node;

	node = ft_dlist_new_node(content);
	if (!node)
	{
		return ;
	}
	ft_dlist_insert_start(&d->head, node);
	if (d->tail == NULL)
	{
		d->tail = node;
	}
}

/**
 * @brief Pop last element of a deque
 * 
 * Pops and returns the content of the last element of the deque.
 * 
 * @see ft_deque_append()
 * @param d Pointer to the deque to pop from.
 * @return The void pointer to the content that was in the node.
*/
void	*ft_deque_pop(t_deque *d)
{
	t_dlist	*node;
	void	*content;
	t_dlist	*prev_node;

	if (!d)
	{
		return (NULL);
	}
	if (d->tail == NULL)
	{
		return (NULL);
	}
	prev_node = d->tail->prev;
	node = ft_dlist_pop_last(&d->tail);
	content = node->content;
	d->tail = prev_node;
	free(node);
	if (d->tail == NULL)
	{
		d->head = NULL;
	}
	return (content);
}
