/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:42:13 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 10:29:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	adds a node to the beginning of a singularly linked list.

	Inputs
	[t_list **] lst_head: a pointer to a pointer to the head of the linked list.
	[t_list *] new_node: a pointer to the new node that will be added to the
			linked list.

	Outputs
	none.
*/
void	lst_add_head(t_list **lst_head, t_list *new_node)
{
	new_node->next = *lst_head;
	*lst_head = new_node;
}
