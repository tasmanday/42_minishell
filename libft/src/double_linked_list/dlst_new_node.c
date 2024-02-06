/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:54:29 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 20:54:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	creates and mallocs a new node for a doubly linked list.

	Inputs
	[void *] data: A pointer to the data that will be stored in the new node.

	Outputs
	[t_dlist *] new_node: A pointer to the newly created node.
*/
t_dlist	*dlst_new_node(void *data)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
	{
		error("dlst_new_node malloc error");
		return (NULL);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
