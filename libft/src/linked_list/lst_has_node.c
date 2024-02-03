/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_has_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:44:08 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:51:13 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if a given node is within a singularly linked list.

	Inputs
	[t_list *] lst_head: a pointer to the head of the linked list to be
			searched.
	[t_list *] node_to_find: a pointer to the node to find within the linked
			list.
	
	Outputs
	[bool] true if the node is within the linked list.
	[bool] false if it isn't.
*/
bool	lst_has_node(t_list *lst_head, t_list *node_to_find)
{
	t_list	*curr;

	curr = lst_head;
	while (curr != NULL)
	{
		if (curr == node_to_find)
			return (true);
		curr = curr->next;
	}
	return (false);
}
