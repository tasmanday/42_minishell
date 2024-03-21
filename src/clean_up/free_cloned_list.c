/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cloned_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:55:06 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 20:56:33 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees the memory allocated for each node in a cloned doubly linked list.
	it only needs to free the nodes of the dlist as the data of the cloned
	list is not malloced but instead just poiters to data from the source list.

	Inputs
	[t_dlist *] head: the head of the dlist to be freed;

	Outputs
	none. the function frees the memory allocated for each node in the doubly
	linked list.
*/
void	free_cloned_list(t_dlist *head)
{
	t_dlist	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
