/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 19:57:47 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap_void_ptrs(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief In place bubble sort of a list using a provided comparison function.
 *
 * Bubble sort using cmp function as comparator. Sort is performed in place.
 * Items are sorted by moving around the content pointers (rather than moving
 * around the list nodes of the deque themselves).
 *
 * @param head Head of list to be sorted.
 * @param cmp A comparator that can compare the content of the list nodes.
 */
void	list_bubble_sort(t_list *head, int (*cmp)(void *, void *))
{
	size_t	list_length;
	int		swapped;
	t_list	*node;
	size_t	i;

	list_length = ft_lstsize(head);
	swapped = 1;
	while (swapped != 0)
	{
		swapped = 0;
		i = 0;
		node = head;
		while (i < list_length - 1)
		{
			if (cmp(node->content, node->next->content) > 0)
			{
				swap_void_ptrs(&node->content, &node->next->content);
				swapped = 1;
			}
			node = node->next;
			i++;
		}
		list_length--;
	}
}

void	set_initial_vals(int *swapped, size_t *i)
{
	*swapped = 0;
	*i = 0;
}

/**
 * @brief In place bubble sort of a deque using a provided comparison function.
 *
 * Bubble sort using cmp function as comparator. Sort is performed in place.
 * Items are sorted by moving around the content pointers (rather than moving
 * around the dlist nodes of the deque themselves).
 *
 * @param d Deque to be sorted.
 * @param cmp A comparator that can compare the content of the deque nodes.
 */
void	deque_bubble_sort(t_deque d, int (*cmp)(void *, void *))
{
	size_t	list_length;
	int		swapped;
	t_dlist	*node;
	size_t	i;

	if (d.head == NULL)
		return ;
	list_length = ft_deque_length(d);
	swapped = 1;
	while (swapped != 0)
	{
		set_initial_vals(&swapped, &i);
		node = d.head;
		while (i < list_length - 1)
		{
			if (cmp(node->content, node->next->content) > 0)
			{
				swap_void_ptrs(&node->content, &node->next->content);
				swapped = 1;
			}
			node = node->next;
			i++;
		}
		list_length--;
	}
}
