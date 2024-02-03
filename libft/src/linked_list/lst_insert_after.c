/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:02:46 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 09:09:05 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	inserts a node into a singularly linked list after the given original node.

	Inputs
	[t_list *] original_node: a pointer to the original node within the linked
			list.
	[t_list *] node_to_insert: a pointer to the new node to be inserted into
			the linked list after the original node.
	
	Outputs
	none.
*/
void	lst_insert_after(t_list *original_node, t_list *node_to_insert)
{
	node_to_insert->next = original_node->next;
	original_node->next = node_to_insert;
}
