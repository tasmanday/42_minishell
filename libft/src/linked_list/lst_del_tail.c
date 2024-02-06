/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:51:31 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 15:21:03 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes the tail/last node of a singularly linked list.

	Inputs
	[t_list *] lst_head: a pointer to the head of the linked list.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	lst_del_tail(t_list **lst_head, void (*ft_del)(void*))
{
	t_list	*temp;
	t_list	*tail_node;

	if (!lst_head || !*lst_head)
	{
		error("lst_del_tail error: !lst_head");
		return ;
	}
	if (!(*lst_head)->next)
	{
		ft_del((*lst_head)->data);
		free(*lst_head);
		*lst_head = NULL;
		return ;
	}
	temp = *lst_head;
	while (temp->next->next)
		temp = temp->next;
	tail_node = temp->next;
	temp->next = NULL;
	ft_del(tail_node->data);
	free(tail_node);
}
