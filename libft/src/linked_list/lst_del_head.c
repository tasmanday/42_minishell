/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:41:03 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 15:02:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes the head/first node of a singularly linked list.

	Inputs
	[t_list **] lst_head: a pointer to a pointer to the head of the linked
			list. needs to be a double pointer so that changes to lst_head
			will occur outside the function as well.
	ft_del: a function pointer to a function that will be used to delete the
			data stored in the node. no_op function can be used here if the
			data in the node doesn't need to be freed.
	
	Outputs
	none.
*/
void	lst_del_head(t_list **lst_head, void (*ft_del)(void*))
{
	t_list	*temp;

	if (!lst_head || !*lst_head)
	{
		put_error("lst_del_head error");
		return ;
	}
	temp = (*lst_head)->next;
	ft_del((*lst_head)->data);
	free_null((void **)lst_head);
	*lst_head = temp;
}
