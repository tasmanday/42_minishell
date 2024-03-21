/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_swap_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:20:56 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 20:18:56 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	swaps the positions of two adjacent nodes in a doubly linked list.

	Inputs
	[t_dlist **] head: a pointer to the address of the head of the doubly
		linked list. it needs the double pointer so that modifications will
		continue outside of this function.
	[t_dlist *] node1: the first node to be swapped.
	[t_dlist *] node2: the second node to be swapped.

	Outputs
	none. the function modifies the doubly linked list by swapping the
	positions of two adjacent nodes.
*/
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

/*
	Summary
	swaps the positions of two non-adjacent nodes in a doubly linked list.

	Inputs
	[t_dlist **] head: a pointer to the address of the head of the doubly
		linked list. it needs the double pointer so that modifications will
		continue outside of this function.
	[t_dlist *] node1: the first node to be swapped.
	[t_dlist *] node2: the second node to be swapped.

	Outputs
	none. the function modifies the doubly linked list by swapping the
	positions of two non-adjacent nodes.
*/
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

/*
	Summary
	swaps the positions of two nodes in a doubly linked list.

	Inputs
	[t_dlist **] head: a pointer to the address of the head of the doubly
		linked list. it needs the double pointer so that modifications will
		continue outside of this function.
	[t_dlist *] node1: the first node to be swapped.
	[t_dlist *] node2: the second node to be swapped.

	Outputs
	none. the function modifies the doubly linked list by swapping the
	positions of the two nodes.
*/
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
