/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:09:35 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:09:35 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes a node from a doubly linked list.

	Inputs
	[t_dlist **] dlst_head: a pointer to a pointer to the head of the linked
			list. needs to be a double pointer so that changes to dlst_head
			will occur outside the function as well.
	[t_dlist *] node_to_del: a pointer to the node to be deleted from the linked
			list.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	dlst_del_node(t_dlist **dlst_head, t_dlist *node_to_del, \
	void (*ft_del)(void*))
{
	if (!dlst_head || !*dlst_head || !node_to_del || \
	!dlst_has_node(*dlst_head, node_to_del))
	{
		error("dlst_del_node error");
		return ;
	}
	if (node_to_del == *dlst_head)
		return (dlst_del_head(dlst_head, ft_del));
	node_to_del->prev->next = node_to_del->next;
	ft_del(node_to_del->data);
	free(node_to_del);
}
