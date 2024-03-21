/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:39:55 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 13:42:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees the memory allocated for the data element of a linked list.
	this function can be passed to list_del_all() to free allocated memory at
	each node of a linked list before deleting them.

	Inputs
	[void *] data: a pointer to the memory that needs to be freed.

	Outputs
	none. it simply frees the memory pointed to by the data pointer.
*/
void	free_data(void *data)
{
	if (data)
		free(data);
}
