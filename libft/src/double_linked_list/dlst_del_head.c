/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:16:39 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:16:39 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes the head/first node of a doubly linked list.

	Inputs
	[t_dlist **] dlst_head: a pointer to a pointer to the head of the linked
			list. needs to be a double pointer so that changes to lst_head
			will occur outside the function as well.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	dlst_del_head(t_dlist **dlst_head, void (*ft_del)(void*))
{
	t_dlist	*temp;

	if (!dlst_head || !*dlst_head)
	{
		error("dlst_del_head error: !dlst_head");
		return ;
	}
	if (!(*dlst_head)->next)
	{
		ft_del((*dlst_head)->data);
		free_null((void **)dlst_head);
		return ;
	}
	temp = (*dlst_head)->next;
	temp->prev = NULL;
	ft_del((*dlst_head)->data);
	free_null((void **)dlst_head);
	*dlst_head = temp;
}
