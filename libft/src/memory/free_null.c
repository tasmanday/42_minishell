/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:03:19 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:33:51 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	free_null frees the memory associated with the given pointer and then sets
	that pointer to NULL to avoid the possibility of using or dereferencing a
	dangling pointer.
	The function takes a pointer to a pointer (void **mem_ptr) as its argument
	because it is intended to modify the original pointer's value, so it
	requires a pointer to that pointer.

	Inputs
	mem_ptr = a pointer to a pointer representing the memory address of the
	pointer to be freed.

	Outputs
	none.
*/
void	free_null(void **mem_ptr)
{
	if (mem_ptr != NULL && *mem_ptr != NULL)
	{
		free(*mem_ptr);
		*mem_ptr = NULL;
	}
}
