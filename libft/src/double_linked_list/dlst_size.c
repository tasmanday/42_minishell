/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:04:16 by tday              #+#    #+#             */
/*   Updated: 2024/02/04 22:04:16 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	counts the number of nodes in a doubly linked list.

	Inputs
	[t_dlist *] dlst: a pointer to the linked list.

	Outputs
	[int] count: the number of nodes in the linked list.
*/
int	dlst_size(t_dlist *dlst)
{
	int	count;

	count = 0;
	while (dlst)
	{
		count++;
		dlst = dlst->next;
	}
	return (count);
}
