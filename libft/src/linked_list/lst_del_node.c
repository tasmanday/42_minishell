/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:10:53 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 15:04:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes a node from a singularly linked list.

	Inputs
	[t_list **] lst_head: a pointer to a pointer to the head of the linked
			list. needs to be a double pointer so that changes to lst_head
			will occur outside the function as well.
	[t_list *] node_to_del: a pointer to the node to be deleted from the linked
			list.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	lst_del_node(t_list **lst_head, t_list *node_to_del, \
	void (*ft_del)(void*))
{
	t_list	*prev;

	if (!lst_head || !*lst_head || !node_to_del || \
	!lst_has_node(*lst_head, node_to_del))
	{
		error("lst_del_node error");
		return ;
	}
	if (node_to_del == *lst_head)
		return (lst_del_head(lst_head, ft_del));
	prev = lst_get_prev(*lst_head, node_to_del);
	if (!prev)
	{
		error("lst_del_node -> lst_get_prev error");
		return ;
	}
	prev->next = node_to_del->next;
	ft_del(node_to_del->data);
	free(node_to_del);
}
