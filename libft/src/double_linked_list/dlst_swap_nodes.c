/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_swap_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:20:56 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 14:20:13 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	swap_adjacent(t_dlist **head, t_dlist *node1, t_dlist *node2)
{
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (node1->next)
		node1->next->prev = node1;
	if (node2->prev)
		node2->prev->next = node2;
	else
		*head = node2;
}

static void	swap_non_adjacent(t_dlist **head, t_dlist *node1, t_dlist *node2)
{
	t_dlist	*temp_next;
	t_dlist	*temp_prev;

	(void)head;
	temp_next = node1->next;
	node1->next = node2->next;
	node2->next = temp_next;
	temp_prev = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp_prev;
	if (node1->next)
		node1->next->prev = node1;
	if (node1->prev)
		node1->prev->next = node1;
	else
		*head = node1;
	if (node2->next)
		node2->next->prev = node2;
	if (node2->prev)
		node2->prev->next = node2;
	else
		*head = node2;
}

void	dlst_swap_nodes(t_dlist **head, t_dlist *node1, t_dlist *node2)
{
	t_dlist	*temp;

	if (node1 == node2 || !head || !*head || !node1 || !node2)
		return ;
	if (node1->prev == node2)
	{
		temp = node1;
		node1 = node2;
		node2 = temp;
	}
	if (node1->next == node2)
		swap_adjacent(head, node1, node2);
	else
		swap_non_adjacent(head, node1, node2);
}
