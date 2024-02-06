/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:39:34 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:39:34 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	deletes all nodes in a doubly linked list.

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
void	dlst_del_all(t_dlist **dlst_head, void (*ft_del)(void*))
{
	if (!dlst_head || !*dlst_head)
	{
		error("dlst_del_all error: !dlst_head");
		return ;
	}
	while (*dlst_head)
		dlst_del_head(dlst_head, ft_del);
}
