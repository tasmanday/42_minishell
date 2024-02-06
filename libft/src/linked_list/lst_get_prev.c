/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:31:27 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:15:35 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	itterates through a singularly linked list to find the node that preceeds a
	given node.

	Inputs
	[t_list *] lst_head: a pointer to the head of the linked list.
	[t_list *] curr: a pointer to the current node in the linked list.

	Outputs
	[t_list *] prev: a pointer to the node that precedes the given curr node in
			the linked list.
*/
t_list	*lst_get_prev(t_list *lst_head, t_list *curr)
{
	t_list	*prev;

	if (!lst_head || !curr || curr == lst_head)
	{
		error("lst_get_prev error");
		return (NULL);
	}
	prev = lst_head;
	while (prev->next != NULL && prev->next != curr)
		prev = prev->next;
	return (prev);
}
