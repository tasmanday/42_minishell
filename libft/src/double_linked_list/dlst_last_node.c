/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_last_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:00:19 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:00:19 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	itterates through the given doubly linked list and returns the last node.

	Inputs
	[t_dlist *] dlst_head: a pointer to the beginning of the linked list.

	Outputs
	[t_dlist *] last_node: a pointer to the last node in the linked list.
*/
t_dlist	*dlst_last_node(t_dlist *dlst_head)
{
	t_dlist	*last_node;

	if (!dlst_head)
	{
		error("dlst_last_node error: !dlst_head");
		return (NULL);
	}
	last_node = dlst_head;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}
