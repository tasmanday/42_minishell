/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:25:03 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:25:03 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes the tail/last node of a doubly linked list.

	Inputs
	[t_dlist *] dlst_head: a pointer to the head of the linked list.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	dlst_del_tail(t_dlist **dlst_head, void (*ft_del)(void*))
{
	t_dlist	*temp;
	t_dlist	*tail_node;

	if (!dlst_head || !*dlst_head)
	{
		error("dlst_del_tail error: !dlst_head");
		return ;
	}
	if (!(*dlst_head)->next)
	{
		ft_del((*dlst_head)->data);
		free_null((void **)dlst_head);
		return ;
	}
	tail_node = dlst_last_node(*dlst_head);
	temp = tail_node->prev;
	temp->next = NULL;
	ft_del(tail_node->data);
	free(tail_node);
}
