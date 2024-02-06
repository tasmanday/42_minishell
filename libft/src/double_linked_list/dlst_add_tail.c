/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:15:36 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 21:15:36 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	adds a node to the end of a doubly linked list.

	Inputs
	[t_dlist **] dlst_head: a pointer to a pointer to the linked list.
	[t_dlist *] new_node: a pointer to the new node that will be added to the
			linked list.

	Outputs
	none.
*/
void	dlst_add_tail(t_dlist **dlst_head, t_dlist *new_node)
{
	t_dlist	*last_node;

	if (!*dlst_head)
	{
		dlst_add_head(dlst_head, new_node);
		return ;
	}
	last_node = dlst_last_node(*dlst_head);
	last_node->next = new_node;
	new_node->prev = last_node;
}
