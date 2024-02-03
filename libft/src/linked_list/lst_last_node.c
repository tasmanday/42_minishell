/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:16:07 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 10:31:12 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	itterates through the given singularly linked list and returns the last
	node.

	Inputs
	[t_list *] lst_head: a pointer to the beginning of the linked list.

	Outputs
	[t_list *] last_node: a pointer to the last node in the linked list.
*/
t_list	*lst_last_node(t_list *lst_head)
{
	t_list	*last_node;

	if (!lst_head)
		return (NULL);
	last_node = lst_head;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}
