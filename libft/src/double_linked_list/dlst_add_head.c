/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:08:06 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 21:08:06 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	adds a node to the beginning of a doubly linked list.

	Inputs
	[t_dlist **] lst_head: a pointer to a pointer to the head of the linked
			list.
	[t_dlist *] new_node: a pointer to the new node that will be added to the
			linked list.

	Outputs
	none.
*/
void	dlst_add_head(t_dlist **dlst_head, t_dlist *new_node)
{
	new_node->next = *dlst_head;
	new_node->prev = NULL;
	if (*dlst_head)
		(*dlst_head)->prev = new_node;
	*dlst_head = new_node;
}
