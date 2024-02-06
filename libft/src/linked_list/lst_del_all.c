/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:23:24 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 15:19:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes all nodes in a singularly linked list.

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
void	lst_del_all(t_list **lst_head, void (*ft_del)(void*))
{
	if (!lst_head || !*lst_head)
	{
		error("lst_del_all error: !lst_head");
		return ;
	}
	while (*lst_head)
		lst_del_head(lst_head, ft_del);
	*lst_head = NULL;
}
