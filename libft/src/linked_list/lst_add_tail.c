/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:47:58 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 10:29:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	adds a node to the end of a singularly linked list.

	Inputs
	[t_list **] lst_head: a pointer to a pointer to the linked list.
	[t_list *] new_node: a pointer to the new node that will be added to the
			linked list.

	Outputs
	none.
*/
void	lst_add_tail(t_list **lst_head, t_list *new_node)
{
	t_list	*last_node;

	if (!*lst_head)
	{
		lst_add_head(lst_head, new_node);
		return ;
	}
	last_node = lst_last_node(*lst_head);
	last_node->next = new_node;
}
