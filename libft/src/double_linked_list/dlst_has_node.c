/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_has_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:06:38 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:06:38 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if a given node is within a doubly linked list.

	Inputs
	[t_dlist *] dlst_head: a pointer to the head of the linked list to be
			searched.
	[t_dlist *] node_to_find: a pointer to the node to find within the linked
			list.
	
	Outputs
	[bool] true if the node is within the linked list.
	[bool] false if it isn't.
*/
bool	dlst_has_node(t_dlist *dlst_head, t_dlist *node_to_find)
{
	t_dlist	*curr;

	curr = dlst_head;
	while (curr != NULL)
	{
		if (curr == node_to_find)
			return (true);
		curr = curr->next;
	}
	return (false);
}
