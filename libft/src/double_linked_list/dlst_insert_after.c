/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_insert_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:23 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 21:23:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	inserts a node into a doubly linked list after the given original node.

	Inputs
	[t_dlist *] original_node: a pointer to the original node within the linked
			list.
	[t_dlist *] node_to_insert: a pointer to the new node to be inserted into
			the linked list after the original node.
	
	Outputs
	none.
*/
void	dlst_insert_after(t_dlist *original_node, t_dlist *node_to_insert)
{
	node_to_insert->next = original_node->next;
	node_to_insert->prev = original_node;
	original_node->next = node_to_insert;
	if (node_to_insert->next)
		node_to_insert->next->prev = node_to_insert;
}
